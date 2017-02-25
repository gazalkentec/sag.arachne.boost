#ifndef _LOGGER_H_
#define _LOGGER_H_

#include <boost/log/expressions.hpp>
#include <boost/log/sources/global_logger_storage.hpp>
#include <boost/log/support/date_time.hpp>
#include <boost/log/trivial.hpp>
#include <boost/log/utility/setup.hpp>

enum severity_level
{
	trace,
	debug,
	info,
	warning,
	error,
	critical
};

template<typename CharT, typename TraitsT>
inline std::basic_ostream<CharT, TraitsT>& operator << (std::basic_ostream<CharT, TraitsT>& strm, severity_level lvl)
{
	static const char* const str[] =
	{
		"trace",
		"debug",
		"info",
		"warning",
		"error",
		"critical"
	};

	if (static_cast<std::size_t>(lvl) < (sizeof(str) / sizeof(*str)))
		strm << str[lvl];
	else
		strm << static_cast<int>(lvl);
	return strm;
}

#define _TRACE	BOOST_LOG_SEV(my_logger::get(), trace)
#define DEBUG	BOOST_LOG_SEV(my_logger::get(), debug)
#define _INFO	BOOST_LOG_SEV(my_logger::get(), info)
#define _WARN	BOOST_LOG_SEV(my_logger::get(), warning)
#define _ERROR	BOOST_LOG_SEV(my_logger::get(), error)
#define _CRIT	BOOST_LOG_SEV(my_logger::get(), critical)

typedef boost::log::sources::severity_logger_mt<severity_level> logger_t;
BOOST_LOG_GLOBAL_LOGGER(my_logger, logger_t)

#endif _LOGGER_H_