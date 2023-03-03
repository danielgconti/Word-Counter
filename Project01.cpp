#include <iostream>
#include <string>




// Build your functions here.




bool AtListPosition(const std::string & word_list, const std::string & word, size_t pos){
 std::string new_string;
 size_t index = 0;
 for(size_t i=pos; i < word_list.length() && index < word.length(); ++i){
   //If not equal
   if(word_list.at(i) != word.at(index)){
     return false;
   //If are
   } else {
     if(new_string.empty()){
       if(i == 0){
         new_string += word_list.at(i);
       } else if(i > 0 && word_list.at(i-1) == ','){
         new_string += word_list.at(i);
       } else {
         return false;
       }
     } else {
       if(word_list.at(i) == word.at(index)){
         new_string += word_list.at(i);
       } else {
         return false;
       }
     }
     if(new_string == word){
       if(i == word_list.length()-1){
         return true;
       } else {
         if(word_list.at(i+1) == ','){
           return true;
         } else {
           return false;
         }
       }
     } else {
       ++index;
       continue;
     }
   }
 }
 return false;
}




size_t FindInList(const std::string & word_list, const std::string & word, size_t pos=0){
for(size_t i=pos; i < word_list.length(); ++i){
  if(AtListPosition(word_list, word, i)){
    return i;
    break;
  }
}
return -1;
}




std::string GetFirstInList(const std::string & word_list, std::string * word1_ptr, std::string * word2_ptr){
if(FindInList(word_list, *word1_ptr, 0) < FindInList(word_list, *word2_ptr, 0)){
  return *word1_ptr;
} else if(FindInList(word_list, *word1_ptr, 0) > FindInList(word_list, *word2_ptr, 0)){
  return *word2_ptr;
} else {
  return "N/A";
}
}




size_t CountInList(const std::string & word_list, const std::string & word){
size_t word_count=0;
for(int i=0; i < static_cast<int>(word_list.length()); ++i){
  if(AtListPosition(word_list, word, i)){
    if(i == 0){
      ++word_count;
    } else if(word_list.at(i-1) == ',' && (word_list.length() <= (i + word.length()))){
      ++word_count;
    } else if(word_list.at(i-1) == ',' && word_list.at(i+word.length()) == ','){
      ++word_count;
    } else {
      continue;
    }
  }
}
return word_count;
}




int main() {
 std::string word1;
 std::string word2;
 std::string input;
 std::string result;
 std::string output;


 std::cin >> word1;
 std::cin >> word2;
  std::getline(std::cin, input);


 while (std::getline(std::cin, input)) {
  output += GetFirstInList(input, &word1, &word2) + " " + std::to_string(CountInList(input, word1)) + " " + std::to_string(CountInList(input, word2)) + "\n";
 }


 std::cout << std::endl << output << std::endl;
}




