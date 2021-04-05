#pragma once

#include <job/status.hpp>
#include <log/log.hpp>
#include <mkt/adapter.hpp>
#include <mkt/quote.hpp>

namespace miu::testmkt {

class adapter : public mkt::adapter {
  private:
    void init(cfg::settings const& settings) override {
        auto core     = settings.optional<int32_t>("core", -1);
        auto interval = settings.optional<time::delta>("interval", std::chrono::seconds(1));

        add_task("updating", core, interval, &adapter::proc, this);
    }

    void uninit() override { log::debug(+__FUNCTION__); }

    void connect() override { notify_connected(); }

    void disconnect() override { notify_disconnected(); }

    void subscribe(ref::instrument inst) override { notify_subscribed(inst.id()); }

  private:
    void proc(job::status* st) {
        uint32_t id = 0;
        while (st->beat()) {
            auto renewal = get_next(id++ % database()->num_of_instrument());
            auto quote   = renewal.quote();
            quote->set_exchange_time(time::clock::now());
            quote->set_bid(1);
            quote->set_bid_vol(10);
            quote->set_ask(2);
            quote->set_ask_vol(20);
            quote->set_last(1.5);
            quote->set_last_vol(15);
            quote->set_total_vol(100);
            quote->set_turnover(9999.999);
            quote->set_open_interest(200);

            log::info(renewal.index(), renewal.symbol(), quote->exchange_time());
        }
    }
};

}    // namespace miu::testmkt
