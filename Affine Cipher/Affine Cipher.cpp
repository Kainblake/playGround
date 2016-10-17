#include<iomanip>
#include<iostream>
using namespace std;

int main() {
	int alphabet[26] = { 0 };
	char string[] = "KNPGJAODZOGRPWZGNDZOHNGROZTWGEAZTWGZDGWNLRRORMNALVWRLNMZIIBTN";
	
	//��һ����ͳ�������Ǵ��ַ�����ĸƵ��
	for (int i = 0; i < strlen(string); i++) {
		alphabet[string[i] - 65]++;
	}
	cout << "ͳ�Ƴ�����ĸƵ��Ϊ" << endl;
	for (int i = 0; i < 26; i++) {
		cout << (char)(i + 65) << " " << alphabet[i] << endl;
	}
	cout << endl << endl;

	//�����Ǳ����ƽⲿ��
	int possible[3] = { 0,4,19 };	//�ֱ��Ӧԭ����A��E��T�����
	for (int possIndex = 0; possIndex < 3; possIndex++) {
		cout << "########  " << (char)(possible[possIndex] + 65) << "  ########" << endl << endl;
		for (int candidate[3] = { 6,13,25 }, candi = 0; candi < 3; candi++) {	//candidate[i]��ʾԭ����ܺ���������ţ���������ѡ���ֱ���G��N��Z
			
			//��ʽ��ʼ���ݼ��ܹ�ʽ�ͽ��ܹ�ʽ����a,b,k3������ο����ְٿ�
			cout << "����Ϊ" << (char)(possible[possIndex] + 65) << "����Ϊ" << (char)(candidate[candi] + 65) << "���������һ����Ϊa���ڶ�����Ϊb" << endl;
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