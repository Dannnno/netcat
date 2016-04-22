

class Socket {
  public:

  	Socket() {}
  	
  	// Don't allow copy construction/assignment
  	Socket(const Socket& rhs) = delete;
  	Socket& operator=(const Socket& rhs) = delete;

  	// Move construction/assignment only
  	Socket(Socket&& rhs)  {
  		std::swap(socktype_, rhs.socktype_);
  		std::swap(file_descriptor_, rhs.file_descriptor_);
  	}

  	Socket& operator=(Socket&& rhs) {
  		std::swap(socktype_, rhs.socktype_);
  		std::swap(file_descriptor_, rhs.file_descriptor_);
  		return *this;
  	}


  private:
  	int socktype_;
  	int file_descriptor_;	

};