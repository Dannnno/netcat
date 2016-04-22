#pragma once

#include <iterator>
#include <string>

// enum class IpVersion : int {
//     AGNOSTIC = AF_UNSPEC;
//     IPv4 = AF_INET;
//     IPv6 = AF_INET6;
// };

// enum class SocketType : int {
//     TCP = SOCK_STREAM;
//     UDP = SOCK_DGRAM;
// };

// union IpAddress {
//     uint32_t ipv4_address_;
//     unsigned char ipv6_address_;
// }

struct SocketAddress {
    enum class SockAddrType : char {
        unknown,
        sockaddr,
        sockaddr_in,
        sockaddr_in6,
        sockaddr_storage
    };

    SocketAddress() : type_(SockAddrType::unknown) {
        memset(data_, 0, sizeof(sockaddr_storage) * sizeof(char));
    }

    SocketAddress(const sockaddr* const address) : type_(SockAddrType::sockaddr) {
        memcpy(data_, address, sizeof(sockaddr));
    }

    SocketAddress(const sockaddr_in* const address) : type_(SockAddrType::sockaddr_in) {
        memcpy(data_, address, sizeof(sockaddr_in));
    }

    SocketAddress(const sockaddr_in6* const address) : type_(SockAddrType::sockaddr_in6) {
        memcpy(data_, address, sizeof(sockaddr_in));
    }
    
    SocketAddress(const sockaddr_storage* const address) : type_(SockAddrType::sockaddr_storage) {
        memcpy(data_, address, sizeof(sockaddr_storage));
    }

    explicit operator sockaddr*() const {
        return static_cast<sockaddr*>(data_);
    }

    explicit operator sockaddr_in*() const {
        return static_cast<sockaddr_in*>(data_);
    }

    explicit operator sockaddr_in6*() const {
        return static_cast<sockaddr_in6*>(data_);
    }

    explicit operator sockaddr_storage*() const {
        return static_cast<sockaddr_storage*>(data_);
    }

    SockAddrType type_;
    char data_[sizeof(sockaddr_storage)];
};

// struct SocketAddress {
//     SocketAddress(const sockaddr* address, IpVersion family, size_t address_size)
//      : address_(address), family_(family), address_size(address_size_) { }

//     int family() const {
//         return family_;
//     }

//     unsigned short port() const {
//         bool ipv4_family = family == AF_INET;
//         bool ipv4_size = address_size_ == sizeof(struct sockaddr_in);

//         if (ipv4_family && ipv4_size) {
//             return static_cast<struct sockaddr_in*>(address_)->sin_port;
//         } else if (!(ipv4_family || ipv4_size)) {
//             return static_cast<struct sockaddr_in6*>(address_)->sin6_port;
//         } else {
//             raise std::runtime_error("Family and struct size don't match, can't determine port attribute name");
//         }
//     }



//     size_t address_size() const {
//         return address_size_;
//     }

//     sockaddr* address_;
//     IpVersion family_;
//     size_t address_size_;
// };

// struct AddressInfo {
//     AddressInfo(const addrinfo* address) : address_(address) { }

//     size_t address_size() const {
//         return address_->ai_addrlen;
//     }

//     sockaddr* address() const {
//         return address_->ai_addr;
//     }

//     std::string canonical_name() const {
//         return std::string(address_->ai_canonname);
//     }

//     IpVersion family() const {
//         return address_->ai_family;
//     }

//     SocketType socket_type() const {
//         return address_->ai_socktype;
//     }

//     SocketType socktype() const {
//         return socket_type();
//     }

//     int flags() const {
//         return address_->ai_flags;
//     }

//     int protocol() const {
//         return address_->protocol;
//     }

//     struct addrinfo* address_;
// };

// class PossibleAddresses {
//   template <typename T>
//   class Iterator;
//   public:
//     using iterator = Iterator<addrinfo*>;
//     using const_iterator = Iterator<const addrinfo*>;

//   private:
//     AddressInfo head_;


// }


int main() {

}