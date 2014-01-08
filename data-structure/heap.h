class heap{

  vector<int> arr;
	int currHeapSize;
	int maxHeapSize;

public :	
	heap ( int size){
		this->currHeapSize = 0;
		double h = log((double)size+1) / (log((double)2));
		h = ceil(h);
		this->maxHeapSize = pow(2.0,h);
		this->arr.resize((this->maxHeapSize));
	}
	
	void addToHeap(const int ele){
		this->arr[this->currHeapSize] = ele;
		heapify(this->currHeapSize);
		(this->currHeapSize)++;
	}

	int extract(){
		if(currHeapSize == 0)
			return -1;
		int val = this->arr[0];
		this->arr[0] = this->arr[currHeapSize-1];
		currHeapSize--;
		int pos = 0;
		int mark = pos;
		while(1){
			if( (left(pos) < currHeapSize) && this->arr[left(pos)] < this->arr[pos])
				mark = left(pos);
			if ( (right(pos) < currHeapSize) && this->arr[right(pos)] < this->arr[pos])
				mark = right(pos);
			if( mark!=pos){	
				int temp = this->arr[pos];
				this->arr[pos] = this->arr[mark];
				this->arr[mark] = temp;
				pos = mark;
			}else
				break;
		}

	return val;
}

private :
	void heapify(int pos){
		while(pos > 0 && p(pos)>=0){
		if( this->arr[p(pos)] > this->arr[pos]){
			int temp = this->arr[pos];
			this->arr[pos] = this->arr[p(pos)];
			this->arr[p(pos)]= temp;
			pos = p(pos);
		}else
			break;
		}
	}
	int left(int n) { return (2*n+1);}
	int right(int n){ return (2*n+2);}
	int p(int n)	{ return ((n-1)/2);}

};
