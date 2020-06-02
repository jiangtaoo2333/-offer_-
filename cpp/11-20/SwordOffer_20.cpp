bool scanUnsignInt(const char** str) {

	const char* before = *str;

	while (**str != '\0' && **str >= '0' && **str <= '9') {
		++(*str);
	}

	return *str > before;
}

bool scanInt(const char** str) {

	if (**str == '-' || **str == '+') {
		++(*str);
	}

	return scanUnsignInt(str);
}

bool isNumber(const char* str) {

	if (str == nullptr) {
		return false;
	}

	bool numeric = scanInt(&str);

	if (*str == '.') {
		numeric = scanUnsignInt(&str) || numeric;
	}

	if (*str == 'e') {
		numeric = scanInt(&str) && numeric;
	}

	return numeric && *str == '\0';

}