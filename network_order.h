#include <cstdint>

// http://stackoverflow.com/a/4410728/3076272
#if defined(__linux__)
#  include <endian.h>
#elif defined(__FreeBSD__) || defined(__NetBSD__)
#  include <sys/endian.h>
#elif defined(__OpenBSD__)
#  include <sys/types.h>
#  define be16toh(x) betoh16(x)
#  define be32toh(x) betoh32(x)
#  define be64toh(x) betoh64(x)
#endif

template <typename T, typename SizeType>
struct IntegralAndSizeEqual {
	using type = typename 
		std::enable_if<
			std::is_integral<T>::value
			&& sizeof(T) == sizeof(SizeType)
		>::type;
};

template <typename T, typename IntegralAndSizeEqual<T, uint16_t>::type>
T to_network_byte_order(T value) {
	return htobe16(value);
}

template <typename T, typename IntegralAndSizeEqual<T, uint32_t>::type>
T to_network_byte_order(T value) {
	return htobe32(value);
}

template <typename T, typename IntegralAndSizeEqual<T, uint64_t>::type>
T to_network_byte_order(T value) {
	return htobe64(value);
}

template <typename T, typename IntegralAndSizeEqual<T, uint16_t>::type>
T to_host_byte_order(T value) {
	return be16toh(value);
}

template <typename T, typename IntegralAndSizeEqual<T, uint32_t>::type>
T to_host_byte_order(T value) {
	return be32toh(value);
}

template <typename T, typename IntegralAndSizeEqual<T, uint64_t>::type>
T to_host_byte_order(T value) {
	return be64toh(value);
}