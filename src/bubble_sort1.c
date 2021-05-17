{
   TFile *f = new TFile("sample_hist.root");
   TH1F *h = (TH1F*)f->Get("sort_hist");
   int data[1000];
   char name[10];
   TObjArray Hlist(0);
   TH1F* h;
   for (int i=0; i<1000; i++)
      data[i] = h->GetBinContent(i+1);
   for (int i=0; i<1000; i++){

      if (i%50==0){             //This part makes root file.
         sprintf(name,"n = %d",i);
         h = new TH1F(name,"Bubble Sort 1",1000,0,1000);
         Hlist.Add(h);
         for (int j=0; j<1000; j++)
            h->SetBinContent(j+1,data[j]);}

      for(int j=0; j<999; j++)
         if(data[j]>data[j+1]){
	    int t= data[j];
	    data[j]=data[j+1];
	    data[j+1]=t;}}

   h = new TH1F("n = 1000","Bubble Sort 1",1000,0,1000);
   Hlist.Add(h);
   for (int j=0; j<1000; j++)
      h->SetBinContent(j+1,data[j]);

   TFile g("bubble_sort1.root","recreate");
   Hlist->Write();
   g.Close();
}

