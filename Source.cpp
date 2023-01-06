#include <iostream>

#include "Menu.h"
#include "File.h"


int main(int argc, char* argv[]) {
	
	TicketingMenu menu;
	File file;
	
	if (argc > 1) {
		std::string filename = argv[1];
		std::cout << "Processing file: " << filename << std::endl;
		// Process the file here
		file.start_files(filename);
		
		
		
		
	}
	else {
		std::cout << "No file specified, using menu mode." << std::endl;
		std::cout << "Create user" << std::endl;
		menu.create_user();
	}



	

}