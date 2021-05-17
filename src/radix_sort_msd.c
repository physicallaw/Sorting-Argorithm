{
   TFile *f = new TFile("sample_hist.root");
   TH1F *h = (TH1F*)f->Get("sort_hist");
   int data[1000], n=0;
   TObjArray Hlist(0);
   TH1F* h;
   for (int i=0; i<1000; i++)
      data[i] = h->GetBinContent(i+1);

   h = new TH1F("n = 1","Radix Sort (MSD)",1000,0,1000);
   Hlist.Add(h);
   for (int j=0; j<1000; j++)
      h->SetBinContent(j+1,data[j]);

   for (int i=100; i<=1000; i+=100)
      for (int j=0; j<1000; j++)
         if (data[j]>=i-100&&data[j]<i){
	    int t=data[n]; data[n]=data[j]; data[j]=t; n++;}

   h = new TH1F("n = 10","Radix Sort (MSD)",1000,0,1000);
   Hlist.Add(h);
   for (int j=0; j<1000; j++)
      h->SetBinContent(j+1,data[j]);

   n=0;
   for(int k=0; k<=900; k+=100){
      for (int i=10; i<=100; i+=10)
         for (int j=0; j<100; j++)
            if (data[j+k]>=i-10+k&&data[j+k]<i+k){
	       int t=data[n]; data[n]=data[j+k]; data[j+k]=t; n++;}
   }

   h = new TH1F("n = 100","Radix Sort (MSD)",1000,0,1000);
   Hlist.Add(h);
   for (int j=0; j<1000; j++)
      h->SetBinContent(j+1,data[j]);

   n=0;
   for(int k=0; k<=990; k+=10){
      for (int i=1; i<=10; i+=1)
         for (int j=0; j<10; j++)
            if (data[j+k]>=i-1+k&&data[j+k]<i+k){
	       int t=data[n]; data[n]=data[j+k]; data[j+k]=t; n++;}
   }

   h = new TH1F("n = 1000","Radix Sort (MSD)",1000,0,1000);
   Hlist.Add(h);
   for (int j=0; j<1000; j++)
      h->SetBinContent(j+1,data[j]);

   TFile g("radix_sort_msd.root","recreate");
   Hlist->Write();
   g.Close();
}

