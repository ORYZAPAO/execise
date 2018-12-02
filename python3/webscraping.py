# coding: UTF-8
#import urllib
import urllib.request
from bs4 import BeautifulSoup

# �A�N�Z�X����URL
url = "http://www.nikkei.com/"

# URL�ɃA�N�Z�X���� html���A���Ă��� �� <html><head><title>�o�ρA�����A�r�W�l�X�A�����̃j���[�X:���o�d�q��</title></head><body....
html = urllib.request.urlopen(url).read()

# html��BeautifulSoup�ň���
soup = BeautifulSoup(html, "html.parser")


lst = soup.select("h2")
for article in lst:
    print(article)
    


# �^�C�g���v�f���擾���� �� <title>�o�ρA�����A�r�W�l�X�A�����̃j���[�X:���o�d�q��</title>
title_tag = soup.title

# �v�f�̕�������擾���� �� �o�ρA�����A�r�W�l�X�A�����̃j���[�X:���o�d�q��
title = title_tag.string

# �^�C�g���v�f���o��
print(title_tag)
print(title)
