{
  
  TCanvas *c1 =new TCanvas();  
  TRandom rndm;
  TH1D *hist=new TH1D("test","test",100,-100,100);
  TRandom random;
  
  for(int i=0;i<10000;i++){
    hist->Fill(random.Gaus(0,10));
  }
  hist->Draw();
}
