{
   TFile *f = new TFile("sample_hist.root");
   TH1F *h = (TH1F*)f->Get("sort_hist");
   int data[1000], save, k;
   char name[10];
   TObjArray Hlist(0);
   TH1F* h;
   for (int i=0; i<1000; i++)
      data[i] = h->GetBinContent(i+1);
   for (int i=0; i<1000; i++){

      if (i%50==0){		//This part makes root file.
	 sprintf(name,"n = %d",i);
	 h = new TH1F(name,"Selection Sort",1000,0,1000);
	 Hlist.Add(h);
	 for (int j=0; j<1000; j++)
            h->SetBinContent(j+1,data[j]);}

      save=1000;
      for(int j=i; j<1000; j++)
         if(data[j]<save){
	    save=data[j]; k=j;}
      data[k]=data[i]; data[i]=save;
   }

   h = new TH1F("n = 1000","Selection Sort",1000,0,1000);
   Hlist.Add(h);
   for (int j=0; j<1000; j++)
      h->SetBinContent(j+1,data[j]);

   TFile g("selection_sort.root","recreate");
   Hlist->Write();
   g.Close();
}