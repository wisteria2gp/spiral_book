# はじめてのgithub チートシート
参考：https://qiita.com/ay3/items/8d758ebde41d256a32dc#%E5%88%9D%E3%82%81%E3%81%A6%E3%81%98%E3%82%83%E3%81%AA%E3%81%84-github-%E9%9A%8F%E6%99%82%E6%9B%B4%E6%96%B0%E4%BA%88%E5%AE%9A


# githubのさいしょ
git remote add origin <h/ttps://github.com/xxx/xxx.git>


## statusかくにん
gis status

## add前変更点かくにん
git diff
### add後
git diff --chached

## stageにあげる
git add <file_name>
### ぜんぶ
git add　--all

## fileの削除
git rm <file_name>

## commit
git commit -m "comment"

## gitでcommitとかしたあと
git push -u origin master
### 2回目からは
git push




## ブランチ作成
git branch <branch_name>

## ブランチ確認 （頭に * のついているのが現在のブランチ）
git branch

## ブランチ切り替え（移動）
git checkout <branch_name>

## 変更一連（ブランチ先にコミットしたりする）
git status
git diff
git add .
git status
git commit -m "comment"

## リモートにPush
git push origin <branch_name>



# 区切りが良くなって、マージしたくなった時 

## マージ先(master)に移動
git checkout master

## さっき作成したブランチをマージ先にマージ
git merge <branch_name>

## ログ確認（さっきのブランチの変更内容がマージ先に反映されているか確認）
git log

## Pushする
git push origin master

## マージ後に削除
git branch -d <branch_name>
git push origin :<branch_name>





















