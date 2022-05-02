#include <iostream>
#include <fstream>
#include <cstdio>
using namespace std;
void c_style(char * file_name) {
  char buffer[100];
  FILE * fp = fopen(file_name, "r");
  if (fp != NULL) {
    // skip first line (csv header)
    fgets(buffer, 100, fp);
    unsigned long id;
    double grade;
    // read csv rows
    while (fscanf(fp, "%lu,%lf", &id, &grade) != EOF) {
      printf("student id: %lu, grade: %lf\n", id, grade);
    }
    // close file
    fclose(fp);
  }
}
void cpp_style(string file_name) {
  ifstream input_file(file_name.c_str());
  if (input_file.is_open()) {
    string line;
    // skip first line (csv header)
    getline(input_file, line);
    // read csv rows
    while (getline(input_file, line)) {
      unsigned long student_id;
      double grade;
      sscanf(line.c_str(), "%lu,%lf", &student_id, &grade);
      cout << "student id: " << student_id << ", grade: " << grade << endl;
    }
    // close file
    input_file.close();
  }
}
int main(int argc, char * argv[]) {
  if (argc < 2) {
    cout << "usage: " << argv[0] << " <input file>" << endl;
    return 1;
  }
  printf("c style file input\n");
  c_style(argv[1]);
  cout << endl << "cpp style file input" << endl;
  cpp_style(string(argv[1]));
  return 0;
}
