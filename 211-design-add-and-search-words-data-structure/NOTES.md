class WordDictionary {
public:
unordered_map<string,int> m;
int n;
WordDictionary() {
}
void addWord(string word) {
n=word.size();
wordsjoin(word,0,n);
}
void wordsjoin(string word,int i,int n){
m[word]=1;
while(i<n){
wordsjoin(word.substr(0,i)+'.'+word.substr(i+1,n-i),i+1,n);
i++;
}
}
bool search(string word) {
if(m[word]==1){
return 1;
}
return 0;
}
};