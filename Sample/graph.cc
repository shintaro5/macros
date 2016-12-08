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
 
  ifstream ifs("point.txt");
  Int_t year[500],month[500],day[500],hour[500],min[500],sec[500];  
  Double_t score[500];
  Double_t time[500];
  
  Double_t tfitrange;
  Double_t tfitstart;
  Double_t tfitend;
  Double_t tdindi;
  vector<double> y,m,d,h,m,s,sc;
  
  TDatime dt[500];
  TDatime dt1[500];
  TDatime dt2[500];
  TDatime ds,de; // start and end
  TDatime dfitstart,dfitend;
  
  ds.Set(2016,11,28,00,00,00);
  de.Set(2016,12,05,02,00,00);
  
  dfitstart.Set(2016,06,27,00,00,00);
  dfitend.Set(2016,07,04,00,00,00);
  
  tfitstart = dfitstart->Convert();
  tfitend   = dfitend->Convert();
  
  Int_t start = ds.Convert();
  Int_t end   = de.Convert();
  Int_t num   = 0;
  Int_t num1  = 0;
  Int_t num2  = 0;
  
  while(!ifs.eof()){
    
    ifs >> year[num] >> month[num] >> day[num] >> hour[num] >> min[num] >> sec[num] >> score[num];
    
    dt[num]->Set(year[num],month[num],day[num],hour[num]+1,min[num],sec[num]);  
    time[num]=dt[num]->Convert();
    
    num++;
  }

  stringstream ss;
  stringstream ss2;
  ss << score[num-2] ;
  ss2 << "saiban_score" << score[num-2] << ".png";

  TGraph *gr = new TGraph(num-1,time,score);
  gPad->SetTicks(0,1);
  gPad->SetFillStyle(0);
  TF1 *f = new TF1("fit","[0]*x+[1]");
  f->SetLineColor(kRed);
  
  
  gr->SetMarkerStyle(20);
  gr->SetMarkerSize(1);
  gr->SetLineColor(kBlack);
  gr->SetMarkerColor(kBlack);
  gr->SetLineWidth(1);
  gr->GetXaxis()->SetTimeFormat("%m/%d %h");
  gr->GetXaxis()->SetTimeOffset(0,"gmt");
  gr->GetXaxis()->SetTimeDisplay(1);  
  gr->GetXaxis()->SetLimits(start,end);
 
  gr->GetYaxis()->SetRangeUser(118000,122000);
  
  TGaxis::SetMaxDigits(6);
  gr->Draw("APL");
  gr->SetLineWidth(1);
  gr->SetLineStyle(1);
  
  gr->GetXaxis()->SetTimeFormat("%m/%d");
  gr->GetXaxis()->SetTimeOffset(0,"gmt");
  gr->GetXaxis()->SetLimits(start,end);
  gr->GetXaxis()->SetTimeDisplay(1);  

}
