{
   TFile *f = new TFile("sample_hist.root");
   TH1F *h = (TH1F*)f->Get("sort_hist");
   int data[1024], k, memory, stack[10]={2,0,0,0,0,0,0,0,0,0}, num=1, sum, ko=0;
   char name[10];
   TObjArray Hlist(0);
   TH1F* h;
   for (int i=0; i<1000; i++)
      data[i] = h->GetBinContent(i+1);
   for (int i=1000; i<1024; i++)
      data[i] = 1000;
   for (int i=0; i<sum+2; i++){
     memory=data[(k=i)];
     while (--k >= sum && memory < data[k]) data[k+1]=data[k];
     data[k+1]=memory;
   }
   for(;;){
      sum=0;
      for (int i=0; i<10; i++) sum+=stack[i];
      if(stack[0]==1024) break;
      if (num>1){
         if (stack[num-2]!=stack[num-1]){
            for (int i=sum; i<sum+2; i++){
               memory=data[(k=i)];
               while (--k >= sum && memory < data[k]) data[k+1]=data[k];
               data[k+1]=memory;
               }
	    stack[num]=2; num++;
         }
         else {

	    if (stack[ko]==2){
	    sprintf(name,"n = %d",ko); ko++;
	    h = new TH1F(name,"Merge Sort",1000,0,1000);
	    Hlist.Add(h);
	    for (int j=0; j<1000; j++)
	       h->SetBinContent(j+1,data[j]);}

            for (int i=sum-2*stack[num-1]; i<sum; i++){
               memory=data[(k=i)];
               while (--k >= sum-2*stack[num-1] && memory < data[k]) data[k+1]=data[k];
               data[k+1]=memory;
               }
	    stack[num-2]*=2; stack[num-1]=0; num--;
         }
      }
      else{
	for (int i=sum; i<sum+2; i++){
	   memory=data[(k=i)];
	   while (--k >= sum && memory < data[k]) data[k+1]=data[k];
	   data[k+1]=memory;
	}
	stack[num]=2; num++;
      }
   }

   h = new TH1F("n = 10","Merge Sort",1000,0,1000);
   Hlist.Add(h);
   for (int j=0; j<1000; j++)
      h->SetBinContent(j+1,data[j]);

   TFile g("merge_sort.root","recreate");
   Hlist->Write();
   g.Close();
}
