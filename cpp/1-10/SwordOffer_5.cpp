
void ReplaceBlank(char string[],int length){
	
	if (string == nullptr) {
		return;
	}
	
	int oriLength = 0;
	int newLength = 0;
	int blank = 0;
	int i = 0;
	while (string[i] != '\n') {
		++oriLength;
		if (string[i] == ' ') {
			blank++;
		}
		i++;
	}
	newLength = oriLength + (2 * blank);

	int indexOri = oriLength;
	int indexNew = newLength;

	while (indexOri >= 0 && indexNew >= indexOri) {
		if (string[indexOri] == ' ') {
			string[indexNew--] = '0';
			string[indexNew--] = '2';
			string[indexNew--] = '%';
			indexOri--;
		}
		else {
			string[indexNew--] = string[indexOri--];
		}
	}
}