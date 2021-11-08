#include <fstream>
#include <iostream>
#include <string>


bool write_to_file(std::string filename, std::string strInput)
{
    //creates new FILENAME.replace
    std::string newFilename = filename;
    newFilename.append(".replace");

    //opens new FILENAME.replace and put strInput out
    std::ofstream outf(newFilename);
    if (!outf) {
		std::cout << newFilename << " could not be opened for writing!" << std::endl;
		return (1);
	}
    outf << strInput;

    return (0);
}

int replace(char **argv) {

	if (argv[2][0] == '\0')
		return (0);
    std::string filename = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];

    //creates inf (input file stream)
    std::ifstream inf(filename);
    if (!inf) {
		std::cout << filename << " could not be opened for reading!" << std::endl;
		return(1);
	}

    //put the file content into the strInput
	std::string strInput;
    size_t pos = 0;
    while (inf) {
        std::string temp;
		inf >> temp;
        strInput.append(temp);
        strInput.append(" ");
	}
			//before
    // while ((pos = strInput.find_last_of(" ")) == strInput.length() - 1){
    //     strInput.erase(pos);
    // }
			//after
	pos = strInput.length() - 2;
	strInput.erase(pos);

    //if two string are the same
    if (s1 == s2) {
        if (write_to_file(filename, strInput) == true)
            return (1);
        return (0);
    }

    //replace all s1 to s2
	pos = 0;
	while ((pos = strInput.find(s1, pos)) != std::string::npos) {
		strInput.erase(pos, s1.length());
		strInput.insert(pos, s2);
		pos += s2.length();
	}

    if (write_to_file(filename, strInput) == true)
        return (1);
    return (0);
}


int main(int argc, char **argv) {

    //SOME ERROR MANAGEMENT SHIT!!!!!!!!!!!!!
    if (argc != 4) {
        std::cout << "PLEASE: use [filename] [s1] [s2] " << std::endl;
        return (1);
    }

    if (replace(argv) == 1)
        return (1);
    return (0);
}