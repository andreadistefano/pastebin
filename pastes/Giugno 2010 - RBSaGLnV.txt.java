public static char[][] m (char[] a) {

	char[][] b = new char[a.length][];
	int i = 0;
	int j = 0;
	for (i = 0; i < a.length; i++) {
		b[i] = new char[i + 1];
		for (j = 0; j < i + 1; j++) {
			b[i][j] = a[i];
		}
	}
	return b;
}

public static char[][] mRic (char[] a) {
	char[][] b = new char[a.length][];
	int i = 0;
	int j = 0;
	return (mRic(a, b, i, j));
}

public static char[][] mRic (char[] a, char[][] b, int i, int j) {
	if (i == a.length) {
		return b;
	}
	if (j == i + 1) {
		return (mRic(a, b, i + 1, 0);
	}
	if (j == 0) {
		b[i] = new char[i + 1];
	}
	b[i][j] = a[i];
	return (mRic(a, b, i, j + 1));
}