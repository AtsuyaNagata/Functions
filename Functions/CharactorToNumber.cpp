bool static isNumber(char c) {
	return (c >= '0' && c <= '9');
}

int CharacterToNumber(const char* name) const {
	int sum = 0, count;
	for (count = 0; isNumber(name[count]); ++count);

	for (int i = 0; i < count; ++i) {
		sum *= 10;
		sum += name[i] - '0';
	}

	return sum;
}