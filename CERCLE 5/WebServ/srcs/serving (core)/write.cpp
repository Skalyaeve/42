#include "../../includes/header.hpp"

// Return une reponse HTTP 1.1
std::string& createAnsw(const std::string& body, const unsigned short& codeRef,
	const std::string& message, const std::string contentType, const std::string& location)
{
	std::ostringstream code;
	std::ostringstream bodySize;

	code << codeRef;
	bodySize << body.size();

	std::string answ =
		"HTTP/1.1 " + code.str() + ' ' + message + "\r\n"
		+ "Server: webServ" + "\r\n"
		+ "Content-Length: " + bodySize.str() + "\r\n";
	if (location.size())
		answ += "Location: " + location + "\r\n";
	else
		answ += "Content-Type: " + contentType + "\r\n";
	answ += "\n\r\n" + body;
	return answ;
}

// Envoie une reponse d'erreur HTTP 1.1
bool sendError(unsigned short codeRef, const std::string message, const int &socket, t_serv& serv, t_location& loca)
{
	// Recupere le nom de la page a ouvrir
	std::string pageName;
	if (serv.errorPages.find(codeRef) != serv.errorPages.end())
		pageName = loca.root + "/" + serv.errorPages[codeRef];
	else
		pageName = data()->defErrorPages[codeRef];

	// Ouvre la page
	std::ifstream page;
	page.open(pageName, std::ios_base::in);
	if (!page)
	{
		std::cerr << "[ ERROR ] cant open() errorPage : " << pageName << " (openin default page for " << codeRef << ")" << std::endl;
		pageName = data()->defErrorPages[codeRef];
		page.open(pageName, std::ios_base::in);
		if (!page)
		{
			std::cerr << "[ ERROR ] cant open() default errorPage : " << pageName << " ..." << std::endl;
			std::cerr << "... Abording, no answer will be send()" << std::endl;
			return false;
		}
	}

	// Remplis le body
	std::stringstream buffer;
	buffer << page.rdbuf();

	const std::string body = buffer.str();
	page.close();

	// Envoie la reponse
	const std::string answ = createAnsw(body, codeRef, message, "text/html", "");
	if (send(socket, answ.c_str(), answ.size(), 0) < 0)
		std::cerr << "[ ERROR ] send() failed to " << socket << std::endl;
	return false;
}
