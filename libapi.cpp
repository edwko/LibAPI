#include "libapi.h"

namespace LIBAPI
{

    const utility::string_t http_client_BYBIT = U("https://api.bybit.com/v2/public");
    const utility::string_t http_client_BITMEX = U("https://www.bitmex.com/api/v1");

    web::json::value getRequest(
        std::vector<std::pair<utility::string_t, utility::string_t>>& UR,
        const utility::string_t& ENDPOINT, const utility::string_t& EXCHANGE)
    {
      
        web::http::client::http_client client(EXCHANGE);

        web::http::uri_builder create_URI(ENDPOINT);

        if (!UR.empty())
        {
            for (std::pair get_data : UR)
            {
                create_URI.append_query(get_data.first, get_data.second);
            }
        }

        web::http::uri rURI = create_URI.to_uri();

        web::http::http_request create_request(web::http::methods::GET);
        create_request.set_request_uri(rURI);

        web::http::http_response get_response = client.request(create_request).get();

        if (get_response.status_code() == web::http::status_codes::OK)
        {
            return get_response.extract_json().get();
        }

        else { return web::json::value(); }

    }

    namespace BYBIT 
    {

        web::json::value ORDER_BOOK(const utility::string_t& SYMBOL_NAME)
        {
            std::vector<std::pair<utility::string_t, utility::string_t>> create_UR;
            create_UR.push_back(std::make_pair(U("symbol"), SYMBOL_NAME));

            return getRequest(create_UR, U("/orderBook/L2"), http_client_BYBIT);
        }

        web::json::value QUERY_KLINE(
            const utility::string_t& SYMBOL_NAME, const utility::string_t& INTERVAL,
            const utility::string_t& TIME_FROM, int LIMIT)
        {
            std::vector<std::pair<utility::string_t, utility::string_t>> create_UR;
            create_UR.push_back(std::make_pair(U("symbol"), SYMBOL_NAME));
            create_UR.push_back(std::make_pair(U("interval"), INTERVAL));
            create_UR.push_back(std::make_pair(U("from"), TIME_FROM));
            LIMIT = LIMIT < 1 ? 1 : LIMIT > 200 ? 200 : LIMIT;
            create_UR.push_back(std::make_pair(U("limit"), utility::conversions::to_string_t(std::to_string(LIMIT))));

            return getRequest(create_UR, U("/kline/list"), http_client_BYBIT);
        }

        web::json::value PRICE_KLINE(
            const utility::string_t& SYMBOL_NAME, const utility::string_t& INTERVAL,
            const utility::string_t& TIME_FROM, int LIMIT)
        {
            std::vector<std::pair<utility::string_t, utility::string_t>> create_UR;
            create_UR.push_back(std::make_pair(U("symbol"), SYMBOL_NAME));
            create_UR.push_back(std::make_pair(U("interval"), INTERVAL));
            create_UR.push_back(std::make_pair(U("from"), TIME_FROM));
            LIMIT = LIMIT < 1 ? 1 : LIMIT > 200 ? 200 : LIMIT;
            create_UR.push_back(std::make_pair(U("limit"), utility::conversions::to_string_t(std::to_string(LIMIT))));

            return getRequest(create_UR, U("/index-price-kline"), http_client_BYBIT);
        }

        web::json::value MARK_KLINE(
            const utility::string_t& SYMBOL_NAME, const utility::string_t& INTERVAL,
            const utility::string_t& TIME_FROM, int LIMIT)
        {
            std::vector<std::pair<utility::string_t, utility::string_t>> create_UR;
            create_UR.push_back(std::make_pair(U("symbol"), SYMBOL_NAME));
            create_UR.push_back(std::make_pair(U("interval"), INTERVAL));
            create_UR.push_back(std::make_pair(U("from"), TIME_FROM));
            LIMIT = LIMIT < 1 ? 1 : LIMIT > 200 ? 200 : LIMIT;
            create_UR.push_back(std::make_pair(U("limit"), utility::conversions::to_string_t(std::to_string(LIMIT))));

            return getRequest(create_UR, U("/mark-price-kline"), http_client_BYBIT);
        }

         web::json::value PREMIUM_KLINE(
            const utility::string_t& SYMBOL_NAME, const utility::string_t& INTERVAL,
            const utility::string_t& TIME_FROM, int LIMIT)
        {
            std::vector<std::pair<utility::string_t, utility::string_t>> create_UR;
            create_UR.push_back(std::make_pair(U("symbol"), SYMBOL_NAME));
            create_UR.push_back(std::make_pair(U("interval"), INTERVAL));
            create_UR.push_back(std::make_pair(U("from"), TIME_FROM));
            LIMIT = LIMIT < 1 ? 1 : LIMIT > 200 ? 200 : LIMIT;
            create_UR.push_back(std::make_pair(U("limit"), utility::conversions::to_string_t(std::to_string(LIMIT))));

            return getRequest(create_UR, U("/premium-index-kline"), http_client_BYBIT);
        }

        web::json::value TICKER(const utility::string_t& SYMBOL_NAME)
        {
            std::vector<std::pair<utility::string_t, utility::string_t>> create_UR;
            create_UR.push_back(std::make_pair(U("symbol"), SYMBOL_NAME));
            return getRequest(create_UR, U("/tickers"), http_client_BYBIT);
        }

        web::json::value PUBLIC_TRADES(const utility::string_t& SYMBOL_NAME, int LIMIT)
        {
            std::vector<std::pair<utility::string_t, utility::string_t>> create_UR;
            create_UR.push_back(std::make_pair(U("symbol"), SYMBOL_NAME));
            LIMIT = LIMIT < 1 ? 1 : LIMIT > 1000 ? 1000 : LIMIT;
            create_UR.push_back(std::make_pair(U("limit"), utility::conversions::to_string_t(std::to_string(LIMIT))));

            return getRequest(create_UR, U("/trading-records"), http_client_BYBIT);
        }

        web::json::value QUERY_SYMBOL()
        {
            std::vector<std::pair<utility::string_t, utility::string_t>> create_UR;
            return getRequest(create_UR, U("/symbols"), http_client_BYBIT);
        }

        web::json::value OPEN_INTEREST(
            const utility::string_t& SYMBOL_NAME,
            const utility::string_t& INTERVAL, int LIMIT)
        {
            std::vector<std::pair<utility::string_t, utility::string_t>> create_UR;
            create_UR.push_back(std::make_pair(U("symbol"), SYMBOL_NAME));
            create_UR.push_back(std::make_pair(U("interval"), INTERVAL));
            LIMIT = LIMIT < 1 ? 1 : LIMIT > 200 ? 200 : LIMIT;
            create_UR.push_back(std::make_pair(U("limit"), utility::conversions::to_string_t(std::to_string(LIMIT))));

            return getRequest(create_UR, U("/open-interest"), http_client_BYBIT);
        }

        web::json::value BIG_DEAL(
            const utility::string_t& SYMBOL_NAME, int LIMIT)
        {
            std::vector<std::pair<utility::string_t, utility::string_t>> create_UR;
            create_UR.push_back(std::make_pair(U("symbol"), SYMBOL_NAME));
            LIMIT = LIMIT < 1 ? 1 : LIMIT > 1000 ? 1000 : LIMIT;
            create_UR.push_back(std::make_pair(U("limit"), utility::conversions::to_string_t(std::to_string(LIMIT))));

            return getRequest(create_UR, U("/big-deal"), http_client_BYBIT);
        }

        web::json::value SERVER_TIME()
        {
            std::vector<std::pair<utility::string_t, utility::string_t>> create_UR;
            
            return getRequest(create_UR, U("/time"), http_client_BYBIT);
        }

    }

    namespace BITMEX
    {

        web::json::value ORDER_BOOK(const utility::string_t& SYMBOL_NAME, int LIMIT)
        {
            std::vector<std::pair<utility::string_t, utility::string_t>> create_UR;
            create_UR.push_back(std::make_pair(U("symbol"), SYMBOL_NAME));
            LIMIT = LIMIT < 1 ? 1 : LIMIT > 200 ? 200 : LIMIT;
            create_UR.push_back(std::make_pair(U("depth"), 
                utility::conversions::to_string_t(std::to_string(LIMIT))));

            return getRequest(create_UR, U("/orderBook/L2"), http_client_BITMEX);
        }

        web::json::value QUOTE(const utility::string_t& SYMBOL_NAME, int LIMIT)
        {
            std::vector<std::pair<utility::string_t, utility::string_t>> create_UR;
            create_UR.push_back(std::make_pair(U("symbol"), SYMBOL_NAME));
            LIMIT = LIMIT < 1 ? 1 : LIMIT > 200 ? 200 : LIMIT;
            create_UR.push_back(std::make_pair(U("depth"), 
                utility::conversions::to_string_t(std::to_string(LIMIT))));

            return getRequest(create_UR, U("/quote"), http_client_BITMEX);
        }

        web::json::value QUOTE_BUCKET(
            const utility::string_t& SYMBOL_NAME, 
            const utility::string_t& TIMEFRAME, int LIMIT)
        {
            std::vector<std::pair<utility::string_t, utility::string_t>> create_UR;
            create_UR.push_back(std::make_pair(U("symbol"), SYMBOL_NAME));
            create_UR.push_back(std::make_pair(U("binSize"), TIMEFRAME));   // 1m, 5m, 1h, 1d
            LIMIT = LIMIT < 1 ? 1 : LIMIT > 200 ? 200 : LIMIT;
            create_UR.push_back(std::make_pair(U("depth"), 
                utility::conversions::to_string_t(std::to_string(LIMIT))));

            return getRequest(create_UR, U("/quote/bucketed"), http_client_BITMEX);
        }

        web::json::value STATS()
        {
            std::vector<std::pair<utility::string_t, utility::string_t>> create_UR;

            return getRequest(create_UR, U("/stats"), http_client_BITMEX);
        }

        web::json::value STATS_HISTORY()
        {
            std::vector<std::pair<utility::string_t, utility::string_t>> create_UR;

            return getRequest(create_UR, U("/stats/history"), http_client_BITMEX);
        }

        web::json::value STATS_HISTORY_USD()
        {
            std::vector<std::pair<utility::string_t, utility::string_t>> create_UR;

            return getRequest(create_UR, U("/stats/historyUSD"), http_client_BITMEX);
        }

        web::json::value SETTLEMENT(const utility::string_t& SYMBOL_NAME, int LIMIT)
        {
            std::vector<std::pair<utility::string_t, utility::string_t>> create_UR;
            create_UR.push_back(std::make_pair(U("symbol"), SYMBOL_NAME));
            LIMIT = LIMIT < 1 ? 1 : LIMIT > 200 ? 200 : LIMIT;
            create_UR.push_back(std::make_pair(U("count"),
                utility::conversions::to_string_t(std::to_string(LIMIT))));

            return getRequest(create_UR, U("/settlement"), http_client_BITMEX);
        }

        web::json::value TRADES(const utility::string_t& SYMBOL_NAME, int LIMIT)
        {
            std::vector<std::pair<utility::string_t, utility::string_t>> create_UR;
            create_UR.push_back(std::make_pair(U("symbol"), SYMBOL_NAME));
            LIMIT = LIMIT < 1 ? 1 : LIMIT > 200 ? 200 : LIMIT;
            create_UR.push_back(std::make_pair(U("count"),
                utility::conversions::to_string_t(std::to_string(LIMIT))));

            return getRequest(create_UR, U("/trade"), http_client_BITMEX);
        }

        web::json::value TRADES_BUCKET(
            const utility::string_t& SYMBOL_NAME,
            const utility::string_t& TIMEFRAME, int LIMIT
        )
        {
            std::vector<std::pair<utility::string_t, utility::string_t>> create_UR;
            create_UR.push_back(std::make_pair(U("symbol"), SYMBOL_NAME));
            create_UR.push_back(std::make_pair(U("binSize"), TIMEFRAME));   // 1m, 5m, 1h, 1d
            LIMIT = LIMIT < 1 ? 1 : LIMIT > 200 ? 200 : LIMIT;
            create_UR.push_back(std::make_pair(U("count"),
                utility::conversions::to_string_t(std::to_string(LIMIT))));

            return getRequest(create_UR, U("/trade/bucketed"), http_client_BITMEX);
        }

    }

}
