
struct Map{
  char key;
  int pre;
};


int main() {
  struct Map pre_in[] = {{'*',2 }, {'/',2}, };
  struct Map pre_out[] = {{'*',3 }, {'/',3}, {'+', 1}, {'-', 1}, {'^', 6}, {'(', 7} };
  
  return 0;
}
