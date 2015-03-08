#ifndef ERRORHANDLER_H
#define ERRORHANDLER_Ho


class ErrorHandler {
	public:
		void logSDLError(std::ostream &os, const std::string &msg);
		bool checkGLError();
		int GLError;
};

#endif