#include<iostream>
#include<list>
#include<string>

using namespace std;

class HashTable{
    private:
    static const int TABLE_SIZE=10;
    
    list<pair<int, string>> table[TABLE_SIZE];
    int hashFunction(int key){
        return key % TABLE_SIZE;
    }
    
    public:
    void insert(int key, string value){
        int index = hashFunction(key);
        
        for(auto &entry:table[index]){
            if(entry.first == key){
                entry.second = value;
                return;
            }
        }
        
        table[index].push_back({key, value});
    }
    
    bool search(int key, string &value){
        int index=hashFunction(key);
        for(auto &entry:table[index]){
            if(entry.first == key){
                value = entry.second;
                return true;
            }
        }
        
        return false;
    }
    
    bool removes(int key){
        int index = hashFunction(key);
        for(auto it = table[index].begin();
            it!= table[index].end();
            ++it){
                if(it->first==key){
                    table[index].erase(it);
                    return true;
                }
            }
            return false;
    }
    
    void display(){
        for(int i=0;i<TABLE_SIZE; i++){
            cout<<i<<": ";
            for(auto &entry:table[i]){
                cout<<"["<<entry.first
                    <<" -> "<<entry.second<<"] ";
            }
            cout<<endl;
        }
    }
};
int main() {
    HashTable ht;

    ht.insert(10, "Alice");
    ht.insert(20, "Bob");
    ht.insert(15, "Charlie");
    ht.insert(25, "David");

    cout << "Hash Table:\n";
    ht.display();

   
    string value;

    if (ht.search(15, value)) {
        cout << "\nKey 15 found: " << value << endl;
    } else {
        cout << "\nKey 15 not found\n";
    }

    
    if (ht.removes(20)) {
        cout << "\nKey 20 removed\n";
    }

    cout << "\nAfter removal:\n";
    ht.display();

    return 0;
}
