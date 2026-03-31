vector<int> sorted;
int n, k;

void merge(vector<int>& v, int l, int m, int r) {
    int i = l;
    int j = m + 1;
    int k = l;
    while (i <= m && j <= r) {
        if (v[i] <= v[j]) {
            sorted[k] = v[i];
            i++;
        } else {
            sorted[k] = v[j];
            j++;
        }
        k++;
    }

    if (i > m) {
        for (int t = j; t <= r; ++t) {
            sorted[k] = v[t];
            k++;
        }
    } else {
        for (int t = i; t <= m; ++t) {
            sorted[k] = v[t];
            k++;
        }
    }

    for (int t = l; t <= r; ++t) {
        v[t] = sorted[t];
    }
}

void mergeSort(vector<int>& v, int l, int r) {
    if (l < r) {
        int m = (l + r) / 2;
        mergeSort(v, l, m);
        mergeSort(v, m + 1, r);
        merge(v, l, m, r);
    }
}
