{
   TFile *f = new TFile("sample_hist.root");
   TH1F *h = (TH1F*)f->Get("sort_hist");
   int data[1000], memo[15]={500,250,200,125,100,50,40,25,20,10,8,5,4,2,1}, memory, k;
   char name[10];
   TObjArray Hlist(0);
   TH1F* h;
   for (int i=0; i<1000; i++)
      data[i] = h->GetBinContent(i+1);
   for (int i=0; i<15; i++){

      sprintf(name,"n = %d",i); 
      h = new TH1F(name,"Shell Sort",1000,0,1000); 
      Hlist.Add(h);
      for (int j=0; j<1000; j++)
         h->SetBinContent(j+1,data[j]);

      for (int j=0; j+memo[i]<1000; j++)
	 if (data[j]>data[j+memo[i]]){
	    int t=data[j]; data[j]=data[j+memo[i]]; data[j+memo[i]]=t;}
   }
   for (int i=0; i<999; i++){
      memory=data[(k=i)];
      while (--k >= 0 && memory < data[k]) data[k+1]=data[k];
      data[k+1]=memory;
      }

   h = new TH1F("n = 15","Shell Sort",1000,0,1000);
   Hlist.Add(h);
   for (int j=0; j<1000; j++)
      h->SetBinContent(j+1,data[j]);

   TFile g("shell_sort.root","recreate");
   Hlist->Write();
   g.Close();
}

