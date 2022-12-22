#pragma once

#include <iostream>
#include <vector>
#include <string>

#include <cpprest/http_client.h>
#include <cpprest/filestream.h>
#include <cpprest/json.h>

namespace LIBAPI
{

	namespace BYBIT
	{

		web::json::value ORDER_BOOK(const utility::string_t& SYMBOL_NAME);

		web::json::value QUERY_KLINE(
			const utility::string_t& SYMBOL_NAME, const utility::string_t& INTERVAL,
			const utility::string_t& TIME_FROM, int LIMIT);

		web::json::value PRICE_KLINE(
			const utility::string_t& SYMBOL_NAME, const utility::string_t& INTERVAL,
			const utility::string_t& TIME_FROM, int LIMIT);

		web::json::value MARK_KLINE(
			const utility::string_t& SYMBOL_NAME, const utility::string_t& INTERVAL,
			const utility::string_t& TIME_FROM, int LIMIT);

		web::json::value PREMIUM_KLINE(
			const utility::string_t& SYMBOL_NAME, const utility::string_t& INTERVAL,
			const utility::string_t& TIME_FROM, int LIMIT);

		web::json::value TICKER(const utility::string_t& SYMBOL_NAME);

		web::json::value PUBLIC_TRADES(const utility::string_t& SYMBOL_NAME, int LIMIT);

		web::json::value QUERY_SYMBOL();

		web::json::value OPEN_INTEREST(
			const utility::string_t& SYMBOL_NAME,
			const utility::string_t& INTERVAL, int LIMIT);

		web::json::value BIG_DEAL(
			const utility::string_t& SYMBOL_NAME, int LIMIT);

		web::json::value SERVER_TIME();

	};

};
