bool static isNumber(char c) {
	return (c >= '0' && c <= '9');
}

double CharacterToNumber(const char* name) {
	double sum = 0;
	//インデックスを指定するための変数
	int i, count;

	//ステージ1 : 小数点以下を考えずに処理
	for (count = 0; isNumber(name[count]); ++count);

	for (i = 0; i < count; ++i) {
		sum *= 10;
		sum += name[i] - '0';
	}

	//もし、区切られ文字が「'.'」の時、少数以下の可能性あり
	if (name[count] == '.') {
		//ステージ2 : 少数点の値の獲得
		i = count + 1;
		for (count = i; isNumber(name[count]); ++count);

		//係数kを用いて少数を表現
		double k = 0.1;
		for (; i < count; ++i) {
			sum += (name[i] - '0') * k;
			k *= 0.1;
		}
	}

	return sum;
}