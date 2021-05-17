{
   TFile *f = new TFile("sample_hist.root");
   TH1F *h = (TH1F*)f->Get("sort_hist");
   int data[1000], memory[1000], n=0;
   char name[10];
   TObjArray Hlist(0);
   TH1F* h;
   for (int i=0; i<1000; i++)
      data[i] = h->GetBinContent(i+1);
   for(int k=1; k<=100; k*=10){

         sprintf(name,"n = %d",k);
         h = new TH1F(name,"Radix Sort (LSD)",1000,0,1000);
         Hlist.Add(h);
         for (int j=0; j<1000; j++)
            h->SetBinContent(j+1,data[j]);

      for (int i=0; i<10; i++){
         for(int j=0; j<1000; j++)
            if((data[j]/k)%10==i){
	       memory[n]=data[j]; n++;}
      }
      for (int i=0; i<1000; i++)
         data[i]=memory[i];
      n=0;
   }

   h = new TH1F("n = 1000","Radix Sort (LSD)",1000,0,1000);
   Hlist.Add(h);
   for (int j=0; j<1000; j++)
      h->SetBinContent(j+1,data[j]);

   TFile g("radix_sort_lsd.root","recreate");
   Hlist->Write();
   g.Close();
}

