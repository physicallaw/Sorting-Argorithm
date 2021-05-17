{
   TFile *f = new TFile("sample_hist.root");
   TH1F *h = (TH1F*)f->Get("sort_hist");
   int data[1000], u, d, save, k;
   TObjArray Hlist(0);
   TH1F* h;
   for (int i=0; i<1000; i++)
      data[i] = h->GetBinContent(i+1);

   h = new TH1F("n = 0","Quick Sort (LR pointers)",1000,0,1000);
   Hlist.Add(h);
   for (int j=0; j<1000; j++)
      h->SetBinContent(j+1,data[j]);

   d=0, u=0;
   while (u+d!=1000){
      if (data[d]<500)
	 d++;
      else if (data[999-u]>=500)
	 u++;
      else{
	 int t=data[d]; data[d]=data[999-u]; data[999-u]=t;}
   }

   h = new TH1F("n = 1","Quick Sort (LR pointers)",1000,0,1000);
   Hlist.Add(h);
   for (int j=0; j<1000; j++)
      h->SetBinContent(j+1,data[j]);

   d=0, u=0;
   while (u+d!=500){
      if (data[d]<250)
	 d++;
      else if (data[499-u]>=250)
	 u++;
      else{
	 int t=data[d]; data[d]=data[499-u]; data[499-u]=t;}
   }
 
   h = new TH1F("n = 2","Quick Sort (LR pointers)",1000,0,1000);
   Hlist.Add(h);
   for (int j=0; j<1000; j++)
      h->SetBinContent(j+1,data[j]);

  d=0, u=0;
   while (u+d!=250){
      if (data[d]<125)
	 d++;
      else if (data[249-u]>=125)
	 u++;
      else{
	 int t=data[d]; data[d]=data[249-u]; data[249-u]=t;}
   }
 
   h = new TH1F("n = 3","Quick Sort (LR pointers)",1000,0,1000);
   Hlist.Add(h);
   for (int j=0; j<1000; j++)
      h->SetBinContent(j+1,data[j]);

  d=0, u=0;
   while (u+d!=125){
      if (data[d]<68)
	 d++;
      else if (data[124-u]>=68)
	 u++;
      else{
	 int t=data[d]; data[d]=data[124-u]; data[124-u]=t;}
   }
 
   h = new TH1F("n = 4","Quick Sort (LR pointers)",1000,0,1000);
   Hlist.Add(h);
   for (int j=0; j<1000; j++)
      h->SetBinContent(j+1,data[j]);

  for(int i=0; i<68; i++){
      save=68;
      for(int j=i; j<68; j++)
	 if(data[j]<save){
	    save=data[j]; k=j;}
      data[k]=data[i]; data[i]=save;
      }
 
   h = new TH1F("n = 5","Quick Sort (LR pointers)",1000,0,1000);
   Hlist.Add(h);
   for (int j=0; j<1000; j++)
      h->SetBinContent(j+1,data[j]);

  for(int i=68; i<125; i++){
      save=125;
      for(int j=i; j<125; j++)
	 if(data[j]<save){
	    save=data[j]; k=j;}
      data[k]=data[i]; data[i]=save;
      }
 
   h = new TH1F("n = 6","Quick Sort (LR pointers)",1000,0,1000);
   Hlist.Add(h);
   for (int j=0; j<1000; j++)
      h->SetBinContent(j+1,data[j]);

  d=0, u=0;
   while (u+d!=125){
      if (data[d+125]<193)
	 d++;
      else if (data[249-u]>=193)
	 u++;
      else{
	 int t=data[d+125]; data[d+125]=data[249-u]; data[249-u]=t;}
   }
 
   h = new TH1F("n = 7","Quick Sort (LR pointers)",1000,0,1000);
   Hlist.Add(h);
   for (int j=0; j<1000; j++)
      h->SetBinContent(j+1,data[j]);

  for(int i=125; i<193; i++){
      save=193;
      for(int j=i; j<193; j++)
	 if(data[j]<save){
	    save=data[j]; k=j;}
      data[k]=data[i]; data[i]=save;
      }
 
   h = new TH1F("n = 8","Quick Sort (LR pointers)",1000,0,1000);
   Hlist.Add(h);
   for (int j=0; j<1000; j++)
      h->SetBinContent(j+1,data[j]);

  for(int i=193; i<250; i++){
      save=250;
      for(int j=i; j<250; j++)
	 if(data[j]<save){
	    save=data[j]; k=j;}
      data[k]=data[i]; data[i]=save;
      }
 
   h = new TH1F("n = 9","Quick Sort (LR pointers)",1000,0,1000);
   Hlist.Add(h);
   for (int j=0; j<1000; j++)
      h->SetBinContent(j+1,data[j]);

  d=0, u=0;
   while (u+d!=250){
      if (data[d+250]<375)
	 d++;
      else if (data[499-u]>=375)
	 u++;
      else{
	 int t=data[d+250]; data[d+250]=data[499-u]; data[499-u]=t;}
   }
 
   h = new TH1F("n = 10","Quick Sort (LR pointers)",1000,0,1000);
   Hlist.Add(h);
   for (int j=0; j<1000; j++)
      h->SetBinContent(j+1,data[j]);

  d=0, u=0;
   while (u+d!=125){
      if (data[d+250]<318)
	 d++;
      else if (data[374-u]>=318)
	 u++;
      else{
	 int t=data[d+250]; data[d+250]=data[374-u]; data[374-u]=t;}
   }
 
   h = new TH1F("n = 11","Quick Sort (LR pointers)",1000,0,1000);
   Hlist.Add(h);
   for (int j=0; j<1000; j++)
      h->SetBinContent(j+1,data[j]);

  for(int i=250; i<318; i++){
      save=318;
      for(int j=i; j<318; j++)
	 if(data[j]<save){
	    save=data[j]; k=j;}
      data[k]=data[i]; data[i]=save;
      }
 
   h = new TH1F("n = 12","Quick Sort (LR pointers)",1000,0,1000);
   Hlist.Add(h);
   for (int j=0; j<1000; j++)
      h->SetBinContent(j+1,data[j]);

  for(int i=318; i<375; i++){
      save=375;
      for(int j=i; j<375; j++)
	 if(data[j]<save){
	    save=data[j]; k=j;}
      data[k]=data[i]; data[i]=save;
      }
 
   h = new TH1F("n = 13","Quick Sort (LR pointers)",1000,0,1000);
   Hlist.Add(h);
   for (int j=0; j<1000; j++)
      h->SetBinContent(j+1,data[j]);


  d=0, u=0;
   while (u+d!=125){
      if (data[d+375]<443)
	 d++;
      else if (data[499-u]>=443)
	 u++;
      else{
	 int t=data[d+375]; data[d+375]=data[499-u]; data[499-u]=t;}
   }
 
   h = new TH1F("n = 14","Quick Sort (LR pointers)",1000,0,1000);
   Hlist.Add(h);
   for (int j=0; j<1000; j++)
      h->SetBinContent(j+1,data[j]);

  for(int i=375; i<443; i++){
      save=443;
      for(int j=i; j<443; j++)
	 if(data[j]<save){
	    save=data[j]; k=j;}
      data[k]=data[i]; data[i]=save;
      }
 
   h = new TH1F("n = 15","Quick Sort (LR pointers)",1000,0,1000);
   Hlist.Add(h);
   for (int j=0; j<1000; j++)
      h->SetBinContent(j+1,data[j]);

  for(int i=443; i<500; i++){
      save=500;
      for(int j=i; j<500; j++)
	 if(data[j]<save){
	    save=data[j]; k=j;}
      data[k]=data[i]; data[i]=save;
      }
 
   h = new TH1F("n = 16","Quick Sort (LR pointers)",1000,0,1000);
   Hlist.Add(h);
   for (int j=0; j<1000; j++)
      h->SetBinContent(j+1,data[j]);

  d=0, u=0;
   while (u+d!=500){
      if (data[d+500]<750)
	 d++;
      else if (data[999-u]>=750)
	 u++;
      else{
	 int t=data[d+500]; data[d+500]=data[999-u]; data[999-u]=t;}
   }
 
   h = new TH1F("n = 17","Quick Sort (LR pointers)",1000,0,1000);
   Hlist.Add(h);
   for (int j=0; j<1000; j++)
      h->SetBinContent(j+1,data[j]);

  d=0, u=0;
   while (u+d!=250){
      if (data[d+500]<625)
	 d++;
      else if (data[749-u]>=625)
	 u++;
      else{
	 int t=data[d+500]; data[d+500]=data[749-u]; data[749-u]=t;}
   }
 
   h = new TH1F("n = 18","Quick Sort (LR pointers)",1000,0,1000);
   Hlist.Add(h);
   for (int j=0; j<1000; j++)
      h->SetBinContent(j+1,data[j]);

  d=0, u=0;
   while (u+d!=125){
      if (data[d+500]<568)
	 d++;
      else if (data[624-u]>=568)
	 u++;
      else{
	 int t=data[d+500]; data[d+500]=data[624-u]; data[624-u]=t;}
   }
 
   h = new TH1F("n = 19","Quick Sort (LR pointers)",1000,0,1000);
   Hlist.Add(h);
   for (int j=0; j<1000; j++)
      h->SetBinContent(j+1,data[j]);

  for(int i=500; i<568; i++){
      save=568;
      for(int j=i; j<568; j++)
	 if(data[j]<save){
	    save=data[j]; k=j;}
      data[k]=data[i]; data[i]=save;
      }
 
   h = new TH1F("n = 20","Quick Sort (LR pointers)",1000,0,1000);
   Hlist.Add(h);
   for (int j=0; j<1000; j++)
      h->SetBinContent(j+1,data[j]);

  for(int i=568; i<625; i++){
      save=625;
      for(int j=i; j<625; j++)
	 if(data[j]<save){
	    save=data[j]; k=j;}
      data[k]=data[i]; data[i]=save;
      }
 
   h = new TH1F("n = 21","Quick Sort (LR pointers)",1000,0,1000);
   Hlist.Add(h);
   for (int j=0; j<1000; j++)
      h->SetBinContent(j+1,data[j]);

  d=0, u=0;
   while (u+d!=125){
      if (data[d+625]<693)
	 d++;
      else if (data[749-u]>=693)
	 u++;
      else{
	 int t=data[d+625]; data[d+625]=data[749-u]; data[749-u]=t;}
   }
 
   h = new TH1F("n = 22","Quick Sort (LR pointers)",1000,0,1000);
   Hlist.Add(h);
   for (int j=0; j<1000; j++)
      h->SetBinContent(j+1,data[j]);

  for(int i=625; i<693; i++){
      save=693;
      for(int j=i; j<693; j++)
	 if(data[j]<save){
	    save=data[j]; k=j;}
      data[k]=data[i]; data[i]=save;
      }
 
   h = new TH1F("n = 23","Quick Sort (LR pointers)",1000,0,1000);
   Hlist.Add(h);
   for (int j=0; j<1000; j++)
      h->SetBinContent(j+1,data[j]);

  for(int i=693; i<750; i++){
      save=750;
      for(int j=i; j<750; j++)
	 if(data[j]<save){
	    save=data[j]; k=j;}
      data[k]=data[i]; data[i]=save;
      }
 
   h = new TH1F("n = 24","Quick Sort (LR pointers)",1000,0,1000);
   Hlist.Add(h);
   for (int j=0; j<1000; j++)
      h->SetBinContent(j+1,data[j]);

  d=0, u=0;
   while (u+d!=250){
      if (data[d+750]<875)
	 d++;
      else if (data[999-u]>=875)
	 u++;
      else{
	 int t=data[d+750]; data[d+750]=data[999-u]; data[999-u]=t;}
   }
 
   h = new TH1F("n = 25","Quick Sort (LR pointers)",1000,0,1000);
   Hlist.Add(h);
   for (int j=0; j<1000; j++)
      h->SetBinContent(j+1,data[j]);

  d=0, u=0;
   while (u+d!=125){
      if (data[d+750]<818)
	 d++;
      else if (data[874-u]>=818)
	 u++;
      else{
	 int t=data[d+750]; data[d+750]=data[874-u]; data[874-u]=t;}
   }
 
   h = new TH1F("n = 26","Quick Sort (LR pointers)",1000,0,1000);
   Hlist.Add(h);
   for (int j=0; j<1000; j++)
      h->SetBinContent(j+1,data[j]);

  for(int i=750; i<818; i++){
      save=818;
      for(int j=i; j<818; j++)
	 if(data[j]<save){
	    save=data[j]; k=j;}
      data[k]=data[i]; data[i]=save;
      }
 
   h = new TH1F("n = 27","Quick Sort (LR pointers)",1000,0,1000);
   Hlist.Add(h);
   for (int j=0; j<1000; j++)
      h->SetBinContent(j+1,data[j]);

  for(int i=818; i<875; i++){
      save=875;
      for(int j=i; j<875; j++)
	 if(data[j]<save){
	    save=data[j]; k=j;}
      data[k]=data[i]; data[i]=save;
      }
 
   h = new TH1F("n = 28","Quick Sort (LR pointers)",1000,0,1000);
   Hlist.Add(h);
   for (int j=0; j<1000; j++)
      h->SetBinContent(j+1,data[j]);

  d=0, u=0;
   while (u+d!=125){
      if (data[d+875]<943)
	 d++;
      else if (data[999-u]>=943)
	 u++;
      else{
	 int t=data[d+875]; data[d+875]=data[999-u]; data[999-u]=t;}
   }
 
   h = new TH1F("n = 29","Quick Sort (LR pointers)",1000,0,1000);
   Hlist.Add(h);
   for (int j=0; j<1000; j++)
      h->SetBinContent(j+1,data[j]);

  for(int i=875; i<943; i++){
      save=943;
      for(int j=i; j<943; j++)
	 if(data[j]<save){
	    save=data[j]; k=j;}
      data[k]=data[i]; data[i]=save;
      }
 
   h = new TH1F("n = 30","Quick Sort (LR pointers)",1000,0,1000);
   Hlist.Add(h);
   for (int j=0; j<1000; j++)
      h->SetBinContent(j+1,data[j]);

  for(int i=943; i<1000; i++){
      save=1000;
      for(int j=i; j<1000; j++)
	 if(data[j]<save){
	    save=data[j]; k=j;}
      data[k]=data[i]; data[i]=save;
      }
 
   h = new TH1F("n = 31","Quick Sort (LR pointers)",1000,0,1000);
   Hlist.Add(h);
   for (int j=0; j<1000; j++)
      h->SetBinContent(j+1,data[j]);

   TFile g("quick_sort.root","recreate");
   Hlist->Write();
   g.Close();
}
