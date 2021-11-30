package Week11;

public class Ex11_1 {

	public static void main(String[] args) {
		int a[] = {34, 27, 19, 51, 8, 24, 11};
		int b[] = {34, 27, 19, 51, 8, 24, 11};
		int c[] = {34, 27, 19, 51, 8, 24, 11};
		int d[] = {34, 27, 19, 51, 8, 24, 11};
		int size = a.length;
		Sort S = new Sort();
		Sort S1 = new Sort();
		Sort S2 = new Sort();
		Sort1 S3 = new Sort1();
		System.out.printf("\n 정렬할 원소 : ");
		for(int i = 0; i<a.length; i++)
			System.out.printf(" %d", a[i]);
		System.out.println();
		S.selectionSort(a);
		S1.bubbleSort(b);
		S2.insertSort(c, size);
		S3.quickSort(d, 0, size-1);
	}
}


class Sort{
	public void selectionSort(int a[]) {
		int i, j, min;
		for(i = 0; i<a.length-1;i++) {
			min = i;
			for(j = i+1; j< a.length; j++) {
				if(a[j] < a[min])
					min = j;
			}
			swap(a, min, i);
			System.out.printf("\n선택 정렬 %d 단계 : ", i+1);
			for(j = 0; j<a.length; j++)
				System.out.printf("%3d", a[j]);
		}
	}
	
	public void bubbleSort(int a[]) {
		int i, j, temp, size;
		size = a.length;
		for(i = size-1; i>0; i--) {
			System.out.printf("\n버블 정렬 %d 단계 : ", size-i);
			for(j = 0; j<i;j++) {
				if (a[j] > a[j+1]) {
					temp = a[j];
					a[j] = a[j+1];
					a[j+1] = temp;
				}
				System.out.printf("\n\t");
				for(int k = 0; k<size; k++)
					System.out.printf("%3d ", a[k]);
			}
		}
	}
	
	public void insertSort(int a[], int size) {
		int i, j, t, temp;
		for(i = 1; i<size; i++) {
			temp = a[i];
			j = i;
			while((j>0) && (a[j-1]>temp)) {
				a[j] = a[j-1];
				j--;
			}
			a[j] = temp;
			System.out.printf("\n삽입정렬 %d 단계 : ", i);
			for(t = 0; t<size; t++)
				System.out.printf("%3d ", a[t]);
		}
		System.out.println();
	}
	
	public void swap(int a[], int i, int j) {
		int temp = a[i];
		a[i] = a[j];
		a[j] = temp;
	}
}

class Sort1{
	int i = 0;
	public int partition(int a[], int begin, int end) {
		int pivot, temp, L, R, t;
		L = begin;
		R = end;
		pivot = (begin + end)/2;
		System.out.printf("\n [퀵정렬 %d 단계 : pivot=%d ]\n", ++i, a[pivot]);
		while(L<R) {
			while((a[L]<a[pivot]) && (L<R))
				L++;
			while((a[R]>=a[pivot]) && (L<R))
				R--;
			if(L<R) {
				temp = a[L];
				a[L] = a[R];
				a[R] = temp;
			}
		}
		temp = a[pivot];
		a[pivot] = a[R];
		a[R] = temp;
		for(t = 0;t<a.length;t++) {
			System.out.printf("%3d ", a[t]);
		}
		System.out.println();
		return L;
	}
	
	public void quickSort(int a[], int begin, int end) {
		if(begin < end) {
			int p;
			p = partition(a, begin, end);
			quickSort(a, begin, p-1);
			quickSort(a, p+1, end);
		}
	}
}
