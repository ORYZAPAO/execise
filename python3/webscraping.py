# coding: UTF-8
#import urllib
import urllib.request
from bs4 import BeautifulSoup

import re

# アクセスするURL
url = "https://www.nikkei.com/"

# URLにアクセスする htmlが帰ってくる → <html><head><title>経済、株価、ビジネス、政治のニュース:日経電子版</title></head><body....
html = urllib.request.urlopen(url).read()

# htmlをBeautifulSoupで扱う
soup = BeautifulSoup(html, "html.parser")


##lst = soup.select("a")
##lst = soup.find_all("a", text=re.compile("article"))
lst = soup.find_all("a", href=re.compile("article"))
for article in lst:
    msg = article.string
    if( msg != None ):
        if( (u"None" != msg) and (u"…続き" != msg) ):
            print(article.string)


# タイトル要素を取得する → <title>経済、株価、ビジネス、政治のニュース:日経電子版</title>
title_tag = soup.title

# 要素の文字列を取得する → 経済、株価、ビジネス、政治のニュース:日経電子版
title = title_tag.string

# タイトル要素を出力
#print(title_tag)
#print(title)
