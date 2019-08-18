bool static isNumber(char c) {
	return (c >= '0' && c <= '9');
}

double CharacterToNumber(const char* name) {
	double sum = 0;
	//�C���f�b�N�X���w�肷�邽�߂̕ϐ�
	int i, count;

	//�X�e�[�W1 : �����_�ȉ����l�����ɏ���
	for (count = 0; isNumber(name[count]); ++count);

	for (i = 0; i < count; ++i) {
		sum *= 10;
		sum += name[i] - '0';
	}

	//�����A��؂�ꕶ�����u'.'�v�̎��A�����ȉ��̉\������
	if (name[count] == '.') {
		//�X�e�[�W2 : �����_�̒l�̊l��
		i = count + 1;
		for (count = i; isNumber(name[count]); ++count);

		//�W��k��p���ď�����\��
		double k = 0.1;
		for (; i < count; ++i) {
			sum += (name[i] - '0') * k;
			k *= 0.1;
		}
	}

	return sum;
}