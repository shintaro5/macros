{
 
  TCanvas *c1=new TCanvas();
  c1->Draw();
  c1->SetGrid(1,1);
  c1->SetCanvasSize(900,700);

  c1->SetFillColor(0);
  c1->SetFillStyle(0);
  c1->SetFrameFillColor(0);
  c1->SetFrameFillStyle(0);
  gStyle->SetNdivisions(508); 
  
  Double_t ymin=106000;
  Double_t ymax=118000;
  
  ifstream ifs("point.txt");
  Int_t year[500];
  Int_t month[500];
  Int_t day[500];
  Int_t hour[500];
  Int_t min[500];
  Int_t sec[500];  
  Double_t score[500];
  Double_t time[500];
  
  Double_t tfitend;
  Double_t tdindi;
  vector<double> y,m,d,h,m,s,sc;
  
  TDatime dt[500];
  TDatime ds,de; 
  TDatime dfitstart,dfitend;
  
  ds.Set(2016,02,01,00,00,00);
  de.Set(2016,02,18,24,00,00);
  
  Int_t start = ds.Convert();
  Int_t end   = de.Convert();
  Int_t num   = 0;
 
  while(!ifs.eof()){
    
    ifs >> year[num] 
	>> month[num] 
	>> day[num] 
	>> hour[num] 
	>> min[num] 
	>> sec[num] 
	>> score[num];
    
    dt[num]->Set(year[num],month[num],day[num],hour[num],min[num],sec[num]);  
    time[num]=dt[num]->Convert();
    
    num++;
  }

  TGraph *gr = new TGraph(num-1,time,score);
  gPad->SetTicks(0,1);
  gPad->SetFillStyle(0);
  
  //  gr->SetTitle("Title of Graph")
  gr->SetMarkerStyle(20);
  gr->SetMarkerSize(1);
  gr->SetLineColor(kBlack);
  gr->SetMarkerColor(kBlack);
  gr->SetLineWidth(1);
  gr->GetXaxis()->SetTimeFormat("%m/%d %h");
  gr->GetXaxis()->SetTimeOffset(0,"gmt");
  gr->GetXaxis()->SetTimeDisplay(1);  
  gr->GetXaxis()->SetLimits(start,end);
  gr->GetYaxis()->SetRangeUser(ymin,ymax);
  
  TGaxis::SetMaxDigits(6);
  gr->Draw("APL");
  gr->SetLineWidth(1);
  gr->SetLineStyle(1);
  
  gr->GetXaxis()->SetTimeFormat("%m/%d");
  gr->GetXaxis()->SetTimeOffset(0,"gmt");
  gr->GetXaxis()->SetLimits(start,end);
  gr->GetXaxis()->SetTimeDisplay(1);  

}
