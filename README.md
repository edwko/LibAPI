# LibAPI
Cryptocurrency API library for retrieving data from market endpoints.

### Usage example:

>Please note that this project does not include a rate limiter, so it is important to ensure that you are adhering to the rate limits set by the exchange.

Retrieve last price:

```c++
#include "libapi.h"

int main()
{
	
	web::json::value result = LIBAPI::BYBIT::TICKER(U("BTCUSD"));

	web::json::value last_price = result.at(U("result"))[0].at(U("last_price"));

	std::wcout << last_price << '\n'; // Output: "16818.00"

	// Conver to string
	utility::string_t last_price_t = last_price.as_string();

	std::string last_price_as_string(last_price_t.begin(), last_price_t.end());

	std::cout << "Last price as string: " << last_price_as_string << '\n';
	// Output: Last price as string: 16818.00

	return 0;

}
```

### Dependencies:

This library uses cpprestsdk to retrieve API data.

You can find installation instructions for cpprestsdk in the GitHub repository: [Cpprestsdk Getting Started](https://github.com/microsoft/cpprestsdk#getting-started)
