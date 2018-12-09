# coding: UTF-8
#import urllib

import urllib.request
from bs4 import BeautifulSoup
import re

class Scraping :
    def __init__(self):
        self.url = "https://www.nikkei.com/"

    def getNikkeiNews(self):
        # 日経ニュースのトップ記事を取得
        
        # URLにアクセスする htmlが帰ってくる → <html><head><title>経済、株価、ビジネス、政治のニュース:日経電子版</title></head><body....
        html = urllib.request.urlopen(self.url).read()
        
        # トップ記事を取得（htmlをBeautifulSoupで分析）
        soup = BeautifulSoup(html, "html.parser")
        articleList = soup.contents[2].contents[3].find_all("span",class_=re.compile("titleL"))

        # 記事一覧を作成
        all_msg =""
        for item in articleList:
            msg = item.string
            if( msg != None ):
                all_msg += (msg+"\n")
                print(msg)

        return(all_msg)


scrp = Scraping()
print("---- 日経ニュース -----")
print("")

msg = scrp.getNikkeiNews()
print(msg)


# タイトル要素を取得する → <title>経済、株価、ビジネス、政治のニュース:日経電子版</title>
#title_tag = soup.title

# 要素の文字列を取得する → 経済、株価、ビジネス、政治のニュース:日経電子版
#title = title_tag.stringd

# タイトル要素を出力
#print(title_tag)
#print(title)
