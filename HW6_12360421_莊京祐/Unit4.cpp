//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <algorithm>
#include "Unit4.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm4 *Form4;
//---------------------------------------------------------------------------
__fastcall TForm4::TForm4(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
int n, range, times, *data, *data2, t0, tx, ti;
float *SelT,*InsT,*BubT,*QuiT,*QuiTN,*MerT,*MerTN,*HeapT,*RadT;
void rand_data(int n){
	data = new int [n];
	for(int i=0; i<n; i++){
		 data[i] = rand() % range +1;
	}
}
void copy_data(int n){
	data2 = new int [n];
	for(int i=0; i<n; i++){
		 data2[i] = data[i];
	}
}
void Selection_sort(int times){
	int min;
	copy_data(n);
	t0 = clock();
	for(int i=0; i<n-1; i++){
        min=i;
		for(int j=i; j<n; j++){
			if(data2[j]<data2[min]){
				min=j;
			}
		}
		int temp = data2[min];
		data2[min] = data2[i];
		data2[i]=temp;
	}
	tx = clock();
    Form4->Memo2->Lines->Add("times["+IntToStr(times)+"]");
	Form4->Memo1->Lines->Add("Selection_sort Finish");
	if(Form4->CheckBox10->Checked){
		Form4->Memo1->Lines->Add("times["+IntToStr(times)+"]");
		String r="";
		for(int i=0; i<n; i++){
			r=r+ IntToStr(data2[i])+"->";
		}
		Form4->Memo1->Lines->Add(r);
	}
	Form4->Memo2->Lines->Add("Selection_sort 時間:"+FloatToStr((float)(tx-t0)/CLOCKS_PER_SEC));
}
void Insertion_sort(int times){
	int target, j;
	copy_data(n);
	t0 = clock();
	for(int i=1;i<n; i++){
		target = data2[i];
		j = i;
		while((data2[j-1])>target && (j>0)){
			data2[j] = data2[j-1];
			j--;
		}
		data2[j] = target;
	}
	tx = clock();
	Form4->Memo1->Lines->Add("Insertion_sort Finish");
	if(Form4->CheckBox10->Checked){
		Form4->Memo1->Lines->Add("times["+IntToStr(times)+"]");
		String r="";
		for(int i=0; i<n; i++){
			r=r+ IntToStr(data2[i])+"->";
		}
		Form4->Memo1->Lines->Add(r);
	}
	Form4->Memo2->Lines->Add("Insertion_sort 時間:"+FloatToStr((float)(tx-t0)/CLOCKS_PER_SEC));
}
void Bubble_sort(int times){
	copy_data(n);
	t0 = clock();
	for(int i=0; i < n-1; i++) {
		for(int j=0; j<n -1- i; j++) {
			if(data2[j]>data2[j+1]){
				int temp = data2[j];
				data2[j] = data2[j+1];
				data2[j+1]=temp;
			}
        }
	}
	tx = clock();
	Form4->Memo1->Lines->Add("Bubble_sort Finish");
	if(Form4->CheckBox10->Checked){
		Form4->Memo1->Lines->Add("times["+IntToStr(times)+"]");
		String r="";
		for(int i=0; i<n; i++){
			r=r+ IntToStr(data2[i])+"->";
		}
		Form4->Memo1->Lines->Add(r);
	}

	Form4->Memo2->Lines->Add("Bubble_sort 時間:"+FloatToStr((float)(tx-t0)/CLOCKS_PER_SEC));
}
void Quick_sort_rv(int left, int right){
	int i, j, target;
	if(left<right){
		i = left+1;
		j = right;
		target = data2[left];
		do{
			while(data2[i]<target && i<=j) i++;
			while(data2[j]>=target && i<=j) j--;
			if(i<j){
				int temp = data2[i];
				data2[i] = data2[j];
				data2[j] = temp;
			}
		} while(i<j);
		if(left<j){
		   int temp = data2[left];
		   data2[left] = data2[j];
		   data2[j] = temp;
		}
		Quick_sort_rv(left, j-1);
		Quick_sort_rv(j+1, right);
	}
}

int top;

struct Quick_Q{
	int left;
	int right;
};
struct Quick_Q * Qstack[10000];
struct Quick_Q * newQ(int left, int right){
	struct Quick_Q * Q = new struct Quick_Q;
	Q->left = left;
	Q->right = right;
    return Q;
}

void push(int left, int right){
	Qstack[++top] = newQ(left, right);
}
struct Quick_Q * pop(){
	if(top==0)ShowMessage("top=0");
	return Qstack[top--];
}

void Quick_sort_nrv(){
    copy_data(n);
    struct Quick_Q * Qdata = new struct Quick_Q;
	int left, right, target, i, j;
	t0 = clock();
	left = 0;
	right = n-1;
	push(left,right);
	while(top!=0){
		Qdata = pop();
		target = data[Qdata->left];
		i = Qdata->left+1;
		j = Qdata->right;
		do{
			while(data2[i]<target && i<=j) i++;
			while(data2[j]>=target && i<=j) j--;
			if(i<j){
				int temp = data2[i];
				data2[i] = data2[j];
				data2[j] = temp;
			}
		}while(i<j);
		if(Qdata->left<j){
			int temp = data2[Qdata->left];
			data2[Qdata->left] = data2[j];
			data2[j] = temp;
		}
		if(j+1<Qdata->right)push(j+1, Qdata->right);
		if(Qdata->left<j-1)push(Qdata->left, j-1);
	}
	tx = clock();
    if(Form4->CheckBox10->Checked){
		Form4->Memo1->Lines->Add("times["+IntToStr(times)+"]");
		String r="";
		for(int u=0; u<n; u++){
			r=r+ IntToStr(data2[u])+"->";
		}
		Form4->Memo1->Lines->Add(r);
	}
	Form4->Memo2->Lines->Add("Quick_sort_nrv 時間:"+FloatToStr((float)(tx-t0)/CLOCKS_PER_SEC));
}
int *c;
void temp_c(int n){
	c = new int [n];
}
void Merge(int i, int m, int j, int n){
	int k=i;
	while((i<=m)&&(j<=n)){
		if(data2[i]<=data2[j]) c[k++]=data2[i++];
		else c[k++]=data2[j++];
	}
	while(i<=m)c[k++] = data2[i++];
	while(j<=n)c[k++] = data2[j++];
}
void Merge_sort_rv(int left, int right){
	if(left < right){
		int m = (left + right) / 2;
		Merge_sort_rv(left, m);
		Merge_sort_rv(m + 1, right);
		Merge(left, m, m + 1, right);
		// 將合併結果寫回 data2
		for(int i = left; i <= right; i++){
			data2[i] = c[i];
		}
	}
}
int min(int a, int b) {
	return (a < b) ? a : b;
}
void Merge_sort_nrv(){
    copy_data(n);
	temp_c(n);
	t0 = clock();

	for (int seg = 1; seg < n; seg += seg) {
		for (int start = 0; start < n; start += seg * 2) {
			int mid = min(start + seg - 1, n - 1);
			int end = min(start + seg * 2 - 1, n - 1);
			Merge(start, mid, mid + 1, end);
		}
		// 將暫存陣列 c[] 複製回 data2[]
		for (int i = 0; i < n; i++) {
			data2[i] = c[i];
		}
	}

	tx = clock();

	Form4->Memo1->Lines->Add("Merge_sort_nrv Finish");

	if(Form4->CheckBox10->Checked){
		Form4->Memo1->Lines->Add("times["+IntToStr(times)+"]");
		String r="";
		for(int u=0; u<n; u++){
			r=r+ IntToStr(data2[u])+"->";
		}
		Form4->Memo1->Lines->Add(r);
	}

	Form4->Memo2->Lines->Add("Merge_sort_nrv 時間:" + FloatToStr((float)(tx - t0) / CLOCKS_PER_SEC));
}
int *h;
void temp_h(int n){
	h = new int [n+1];
}
void restore(int s, int t){
	int i=s, j;
	while(i<=t/2){
		if(h[2*i]<h[2*i+1]) j=2*i;
		else j=2*i+1;
		if(h[i]<h[j])break;
		int temp=h[i];
		h[i]=h[j];
		h[j]=temp;
		i=j;
	}
}
void heap_sort(){
	for(int i=n/2; i>=1; i--)
		restore(i,n);
	for(int i=n; i>=1; i--){
		data2[n-i]=h[1];
		h[1]=h[i];
		restore(1,i-1);
	}
}



int getMax(int arr[], int n) {
	int mx = arr[0];
	for (int i = 1; i < n; i++)
		if (arr[i] > mx)
			mx = arr[i];
	return mx;
}

//位元
void countingSort(int arr[], int n, int exp) {
	int* output = new int[n];
	int count[10] = {0};
	for (int i = 0; i < n; i++)
		count[(arr[i] / exp) % 10]++;
	for (int i = 1; i < 10; i++)
		count[i] += count[i - 1];
	for (int i = n - 1; i >= 0; i--) {
		int digit = (arr[i] / exp) % 10;
		output[count[digit] - 1] = arr[i];
		count[digit]--;
	}
	for (int i = 0; i < n; i++)
		arr[i] = output[i];
	delete[] output;
}

void Radix_sort() {
	copy_data(n);
	t0 = clock();

	int m = getMax(data2, n);

	for (int exp = 1; m / exp > 0; exp *= 10)
		countingSort(data2, n, exp);

	tx = clock();

	Form4->Memo1->Lines->Add("Radix_sort Finish");

	if(Form4->CheckBox10->Checked){
		Form4->Memo1->Lines->Add("times["+IntToStr(times)+"]");
		String r="";
			for(int u=0; u<n; u++){
				r=r+ IntToStr(data2[u])+"->";
			}
			Form4->Memo1->Lines->Add(r);
	}

	Form4->Memo2->Lines->Add("Radix_sort 時間:" +
		FloatToStr((float)(tx - t0) / CLOCKS_PER_SEC));
}


void __fastcall TForm4::Button1Click(TObject *Sender)
{   n=StrToInt(Edit1->Text);
	range=StrToInt(Edit2->Text);
	times=StrToInt(Edit3->Text);
	SelT = new float [times]; InsT = new float [times]; QuiT = new float [times];
	QuiTN = new float [times]; MerT = new float [times]; MerTN = new float [times];
	BubT = new float [times]; HeapT = new float [times]; RadT = new float [times];
	for(int i=0; i<times; i++){
		SelT[i]=0;
		InsT[i]=0;
		BubT[i]=0;
		QuiT[i]=0;
		QuiTN[i]=0;
		MerT[i]=0;
		MerTN[i]=0;
		HeapT[i]=0;
		RadT[i]=0;
	}

	for(int i=0; i<times; i++){
		n=n*(i+1);
		rand_data(n);
		if(Form4->CheckBox11->Checked){
			Form4->Memo1->Lines->Add("----------------");
			String r="";
			Form4->Memo1->Lines->Add("原式:");
			for(int u=0; u<n; u++){
					r=r+ IntToStr(data[u])+"->";
			}
			Form4->Memo1->Lines->Add(r);
			Form4->Memo1->Lines->Add("----------------");
		}
		if(CheckBox1->Checked){
			Selection_sort(i);
			SelT[i]= (float)(tx - t0) / CLOCKS_PER_SEC;
		}

		if(CheckBox2->Checked){
			Insertion_sort(i);
			InsT[i]= (float)(tx - t0) / CLOCKS_PER_SEC;
		}

		if(CheckBox3->Checked){
			Bubble_sort(i);
			BubT[i]= (float)(tx - t0) / CLOCKS_PER_SEC;
		}

		if(CheckBox4->Checked){
			copy_data(n);
			t0 = clock();
			Quick_sort_rv(0, n-1);
			tx = clock();
			Form4->Memo1->Lines->Add("Quick_sort_rv Finish");
			if(Form4->CheckBox10->Checked){
				Form4->Memo1->Lines->Add("times["+IntToStr(times)+"]");
				String r="";
				for(int u=0; u<n; u++){
					r=r+ IntToStr(data2[u])+"->";
				}
				Form4->Memo1->Lines->Add(r);
			}
			Form4->Memo2->Lines->Add("Quick_sort_rv 時間:"+FloatToStr((float)(tx-t0)/CLOCKS_PER_SEC));
			QuiT[i]= (float)(tx - t0) / CLOCKS_PER_SEC;
		}

		if(CheckBox5->Checked){
			top=0;
			Quick_sort_nrv();
			QuiTN[i]= (float)(tx - t0) / CLOCKS_PER_SEC;
		}
		if(CheckBox6->Checked){
			temp_c(n);
			copy_data(n);
			t0 = clock();
			Merge_sort_rv(0, n-1);
			tx = clock();
			Form4->Memo1->Lines->Add("Quick_sort_nrv Finish");
			if(Form4->CheckBox10->Checked){
				Form4->Memo1->Lines->Add("times["+IntToStr(times)+"]");
				String r="";
				for(int u=0; u<n; u++){
					r=r+ IntToStr(c[u])+"->";
				}
				Form4->Memo1->Lines->Add(r);
			}
			Form4->Memo2->Lines->Add("Merge_sort_rv 時間:"+FloatToStr((float)(tx-t0)/CLOCKS_PER_SEC));
			MerT[i]= (float)(tx - t0) / CLOCKS_PER_SEC;
		}
		if(CheckBox7->Checked){
			Merge_sort_nrv();
			MerTN[i]= (float)(tx - t0) / CLOCKS_PER_SEC;
		}

		if(CheckBox8->Checked){
			temp_h(n);
			copy_data(n);
			for(int u=1;u<=n;u++){
				h[u]=data2[u-1];
			}
			t0 = clock();
			heap_sort();
			tx = clock();
			Form4->Memo1->Lines->Add("heap_sort_finish");
            if(Form4->CheckBox10->Checked){
				Form4->Memo1->Lines->Add("times["+IntToStr(times)+"]");
				String r="";
				for(int u=0; u<n; u++){
					r=r+ IntToStr(data2[u])+"->";
				}
				Form4->Memo1->Lines->Add(r);
			}
			Form4->Memo2->Lines->Add("heap_sort 時間:"+FloatToStr((float)(tx-t0)/CLOCKS_PER_SEC));
			HeapT[i]= (float)(tx - t0) / CLOCKS_PER_SEC;
		}
		if(CheckBox9->Checked){
			copy_data(n);
			Radix_sort();
            RadT[i]= (float)(tx - t0) / CLOCKS_PER_SEC;
		}


		delete[] data;
	}
}
//---------------------------------------------------------------------------
//Form4->CheckBox5->Checked
//ShowMessage(IntToStr(n));
//Form4->Memo1->Lines->Add(IntToStr(n));
void __fastcall TForm4::Button2Click(TObject *Sender)
{	Chart1->RemoveAllSeries();
	Chart1->Title->Text->Clear();
	Chart1->Title->Text->Add("Sorting Alg");
	Chart1->BottomAxis->Title->Caption = "Data";     //水平座標軸的標題
	Chart1->LeftAxis->Title->Caption = "CPU Time";
	for (int i=1;i<=9;i++){
	TLineSeries *Series=new TLineSeries(Chart1);
	Series->ParentChart=Chart1;
	Chart1->AddSeries(Series);
	}
	Chart1->Series[0]->Color =  clBlue;
	Chart1->Series[0]->Title =  "Selection_sort";
	Chart1->Series[1]->Color =  clBlack;
	Chart1->Series[1]->Title =  "Insertion_sort";
	Chart1->Series[2]->Color =  clYellow;
	Chart1->Series[2]->Title =  "Bubble_sort";
	Chart1->Series[3]->Color =  clTeal;
	Chart1->Series[3]->Title =  "Quick_sort_rv";
	Chart1->Series[4]->Color =  clPurple;
	Chart1->Series[4]->Title =  "Quick_sort_nrv";
	Chart1->Series[5]->Color =  clGreen;
	Chart1->Series[5]->Title =  "Merge_sort_rv";
	Chart1->Series[6]->Color =  clAqua;
	Chart1->Series[6]->Title =  "Merge_sort_nrv";
	Chart1->Series[7]->Color =  clSilver;
	Chart1->Series[7]->Title =  "heap_sort";
	Chart1->Series[8]->Color =  clTeal;
	Chart1->Series[8]->Title =  "Radix_sort";
	for(int i=0; i<times; i++)
		Chart1->Series[0]->Add( SelT[i] , i , clBlue );
	for(int i=0; i<times; i++)
		Chart1->Series[1]->Add( InsT[i] , i , clBlack);
	for(int i=0; i<times; i++)
		Chart1->Series[2]->Add( BubT[i] , i , clYellow );
	for(int i=0; i<times; i++)
		Chart1->Series[3]->Add( QuiT[i] , i , clTeal );
	for(int i=0; i<times; i++)
		Chart1->Series[4]->Add( QuiTN[i] , i , clPurple  );
	for(int i=0; i<times; i++)
		Chart1->Series[5]->Add( MerT[i] , i , clGreen );
	for(int i=0; i<times; i++)
		Chart1->Series[6]->Add( MerTN[i] , i , clAqua);
	for(int i=0; i<times; i++)
		Chart1->Series[7]->Add( HeapT[i] , i , clSilver );
	for(int i=0; i<times; i++)
		Chart1->Series[8]->Add( RadT[i] , i , clTeal );





}
//---------------------------------------------------------------------------

