

# ローカルのフォルダをgithubリモートリポジトリと連携させるとき(初回)














# あとから.gitignoreをいれたときのusage
- .gitignoreを作成
```
#vscodeがつくっちゃうフォルダをgit管理下から外した際
vscode/
```
これでcommit & pushしてもキャッシュが残っているので反映されない
一度リモートリポジトリからキャッシュを消す必要がある
- ファイル全体キャッシュ削除
```
git rm -r --cached .
```
この状態でcommit & pushするとごっそりremoveと出るし
リモートリポジトリからファイルが全部消えるがローカルにはちゃんともとのまま
- 再びローカルからadd & commit & push
```
git add --all
git commit -m "xxxxx"
git push
```

これでgitignoreが反映された元通りの形になる

