#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>   

using namespace std;

/*Writing vector into the sorted file */
void write(vector<string> name){
	ofstream fout;
	fout.open("sorted-names-list.txt");
	for(int i=0;i<name.size();++i){
		fout<<name[i]<<endl;
	}
	fout.close();
}

int main(int argc, char ** argv){

    vector<string> names;
    string line;

    if (argc!=2) {
        cout<<"File Name must enter"<<endl;
        exit(1);
    }

    string filename(argv[1]);
    ifstream input_file(filename);
    
    /* File is present or not*/
    if (!input_file.is_open()) {
        cerr << "Could not open the file - '"
             << filename << "'" << endl;
        return EXIT_FAILURE;
    }

    /*Getting the line from file and store into vector*/
    while (getline(input_file, line)){
        names.push_back(line);
    }

    // Sort the names based on last name 
    sort(names.begin(), names.end(),[] (string &s1, string &s2) { 
        std::size_t found1,found2;

        /*Reterive the position of last name in two strings*/
        found1= s1.find_last_of(" ");
        found2= s2.find_last_of(" ");
        return s1.substr(found1+1) < s2.substr(found2+1); });
   
    write(names);

    /*Printing the sorted list of names on screen*/
    for (const auto &name : names) {
        cout << name << endl;
    }

    /*Closing the input file*/
    input_file.close();


    return 0;
}