#include <iostream>
#include <string>

using namespace std;

int main() {
	string str;
    while(str != ".") {
        cin >> str;
		int i, j, max_s;
		int s;
		int length;		
		for(max_s = 0,length = 1; length <= str.length(); length++)
			if(str.length() % length == 0){
				for(i = 0, s = 1, j=length; str[j]!='\0'; i++, j++) {
					if(i == length){
                        i = 0;
                        s++;
                    }
					if(str[i] != str[j])
						break;
				}
				if(i == length){
                    i = 0;
                    s++;
                }
				if(str[j] == '\0')
					if(s > max_s)
						max_s = s;
			}
        if (str != ".")
            cout << max_s << endl;
	}
	return 0;
}