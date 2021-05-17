{
   TFile *f = new TFile("sample_hist.root");
   TH1F *h = (TH1F*)f->Get("sort_hist");
   int heap[1025]=0, n=1000;
   char name[10];
   TObjArray Hlist(0);
   TH1F* h;
   for (int i=1; i<=1000; i++)
      heap[i] = h->GetBinContent(i);
   while (n!=0){

      if (n%50==0){             //This part makes root file.
         sprintf(name,"n = %d",1000-n);
         h = new TH1F(name,"Heap Sort",1000,0,1000);
         Hlist.Add(h);
         for (int j=1; j<=1000; j++)
            h->SetBinContent(j,heap[j]);}

      for (int k=log(n)/log(2)-1; k>=0; k--)
         for (int i=pow(2,k); i<pow(2,k+1); i++){
	    if (heap[i]<heap[2*i]&&2*i<n){
	       int t=heap[i]; heap[i]=heap[2*i]; heap[2*i]=t;}
	    if (heap[i]<heap[2*i+1]&&2*i+1<n){
	       int t=heap[i]; heap[i]=heap[2*i+1]; heap[2*i+1]=t;}
	 }
      int t=heap[1]; heap[1]=heap[n]; heap[n]=t; n--;
}

   h = new TH1F("n = 1000","Heap Sort",1000,0,1000);
   Hlist.Add(h);
   for (int j=1; j<=1000; j++)
      h->SetBinContent(j+1,heap[j]);

   TFile g("heap_sort.root","recreate");
   Hlist->Write();
   g.Close();



}

