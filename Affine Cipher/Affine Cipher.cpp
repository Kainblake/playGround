#include<iomanip>
#include<iostream>
using namespace std;

int main() {
	int alphabet[26] = { 0 };
	char string[] = "KNPGJAODZOGRPWZGNDZOHNGROZTWGEAZTWGZDGWNLRRORMNALVWRLNMZIIBTN";
	
	//这一段是统计上面那串字符的字母频率
	for (int i = 0; i < strlen(string); i++) {
		alphabet[string[i] - 65]++;
	}
	cout << "统计出的字母频率为" << endl;
	for (int i = 0; i < 26; i++) {
		cout << (char)(i + 65) << " " << alphabet[i] << endl;
	}
	cout << endl << endl;

	//下面是暴力破解部分
	int possible[3] = { 0,4,19 };	//分别对应原码是A，E，T的情况
	for (int possIndex = 0; possIndex < 3; possIndex++) {
		cout << "########  " << (char)(possible[possIndex] + 65) << "  ########" << endl << endl;
		for (int candidate[3] = { 6,13,25 }, candi = 0; candi < 3; candi++) {	//candidate[i]表示原码加密后的密码的序号，有三个待选，分别是G，N，Z
			
			//正式开始根据加密公式和解密公式遍历a,b,k3。详情参考各种百科
			cout << "以下为" << (char)(possible[possIndex] + 65) << "加密为" << (char)(candidate[candi] + 65) << "的情况，第一个数为a，第二个数为b" << endl;
			for (int a = 1; a < 26; a += 2) {
				for (int b = 0; b < 26; b++) {
					if ((possible[possIndex] * a + b) % 26 == candidate[candi] && a != 13) {
						cout << setfill(' ') << setw(3) << a << setfill(' ') << setw(3) << b << " ";
						int k3 = 0;
						for (; k3 < 26; k3++) {
							if ((a*k3) % 26 == 1) {
								for (int i = 0; i < strlen(string); i++) {
									int temp = ((string[i] - 65 - b) * k3) % 26;
									temp = temp < 0 ? temp + 26 : temp;
									cout << (char)(temp + 65);
								}
							}
						}
						cout << endl;
					}
				}
			}
			cout << endl;

		}
		cout << endl;
	}

	return 0;
}