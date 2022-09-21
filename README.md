# 『ふつうのLinuxプログラミング』第2版 サンプルコード

このディレクトリには『ふつうのLinuxプログラミング第2版』の
サンプルコード (+ α) が収録されています。

サポートサイト: https://i.loveruby.net/stdlinux2/

## 必要環境

プログラムをビルドするにはLinuxとgcc、GNU makeが必要です。
動作確認は以下の環境で行いました。

- Ubuntu Linux Desktop 16.04 LTS
- CentOS 7.3

## ビルド方法

このディレクトリにcdし、コマンドラインでmakeコマンドを実行するとすべてのプログラムをビルドできます。
make test でテストを実行します。

## ライセンス

このディレクトリに含まれるソースコードはすべて青木峰郎が
著作権を保持しており、MITライセンスに基きライセンスします。
即ち、目的や対価の有無に関らず変更・再配布・他のプログラム
への組み込みなどを許可します。ただしこのプログラムを利用した
結果生じたトラブルなどについては、いかなる場合も著者ならびに
出版社は責任を負いかねます。

青木峰郎 / Minero Aoki

# ソースコード一覧

## 第1章
<dl>
<dt><a href="hello.c">hello.c</a></dt>
<dd>ありがちなHello, World!</dd>

<dt><a href="args.c">args.c</a></dt>
<dd>コマンドライン引数を表示するプログラム</dd>

<dt><a href="segv.c">segv.c</a></dt>
<dd>NULLポインタを参照するだけのプログラム。
確実にsegmentation faultを起こす。</dd>

<dt><a href="echo.c">echo.c</a></dt>
<dd>簡単なechoコマンド。</dd>
</dl>

## 第4章
<dl>
<dt><a href="bell.c">bell.c</a></dt>
<dd>端末のベルを鳴らすプログラム</dd>
</dl>

## 第5章
<dl>
<dt><a href="cat.c">cat.c</a></dt> [my cat.c](./mysoln/cat.c)
<dd>簡単なcatコマンド (システムコール版)</dd>

<dt><a href="cat0.c">cat0.c</a></dt>
<dd>cat.cからエラー処理を取り除いたコード</dd>

<dt><a href="cat3.c">cat3.c</a></dt> [my soln cat3.c](./mysoln/cat3.c)
<dd>問題5-1の解答例。
コマンドライン引数がないときはstdinを読むcatコマンド</dd>

<dt><a href="wc-l-syscall.c">wc-l-syscall.c</a></dt> [my soln wc-l-syscall.c](./mysoln/wc-l-syscall.c)
<dd>問題5-2の解答例。
標準入力からテキストを読み込み、その行数を表示する。</dd>
</dl>

## 第6章
<dl>
<dt><a href="cat2.c">cat2.c</a></dt>
<dd>stdioを使ったcatコマンド</dd>

<dt><a href="getcperf.c">getcperf.c</a></dt>
<dd>fgetcとgetcの速度を比較するためのプログラム。
何もコマンドライン引数を付けないとgetcを使い、
コマンドライン引数で「f」を渡すとfgetcを使う。</dd>

<dt><a href="feof-bug.c">feof-bug.c</a></dt>
<dd>feofを使ったときに起こる有名なバグを確認するコード。
このプログラムの標準入力にテキストファイルをリダイレクトして実行すると、
最後の行が 2 回表示される。</dd>

<dt><a href="cat-escape.c">cat-escape.c</a></dt>
<dd>問題6-1の解答例。
タブを「\t」、改行を「$」+ 改行で表示するcatコマンド</dd>

<dt><a href="wc-l-stdio.c">wc-l-stdio.c</a></dt>
<dd>問題6-2の解答例。
標準入力からテキストを読み込み、その行数を表示する。</dd>

<dt><a href="cat5.c">cat5.c</a></dt>
<dd>問題6-3の解答例。
freadとfwriteを使ったcatコマンド。</dd>
</dl>

## 第7章
<dl>
<dt><a href="head.c">head.c</a></dt>
<dd>簡単なheadコマンド。stdinのみ読む。</dd>

<dt><a href="head2.c">head2.c</a></dt>
<dd>簡単なheadコマンド。コマンドライン引数のファイルも読む。</dd>

<dt><a href="head3.c">head3.c</a></dt>
<dd>簡単なheadコマンド。
getoptでコマンドラインオプションを解析する例。</dd>

<dt><a href="head4.c">head4.c</a></dt>
<dd>簡単なheadコマンド。
getopt_longでコマンドラインオプションを解析する例。</dd>

<dt><a href="gdb/">gdb/*</a></dt>
<dd>gdbのテストに使ったファイル。</dd>

<dt><a href="cat4.c">cat4.c</a></dt>
<dd>問題7-1の解答例。
-eオプションでcat-escape.cと同じ効果を発揮する
catコマンド。</dd>

<dt><a href="tail.c">tail.c</a></dt>
<dd>問題7-2の解答例。
簡単なtailコマンド（出力行数固定）。</dd>
</dl>

## 第8章
<dl>
<dt><a href="grep.c">grep.c</a></dt>
<dd>8章で作成したgrepコマンド</dd>

<dt><a href="array.c">array.c</a></dt>
<dd>文字列と文字の配列が等しいことを確認するコード</dd>

<dt><a href="wgrep.c">wgrep.c</a></dt>
<dd>wchar を使ってマルチバイト文字にも対応した grep コマンド。
固定文字列しか検索できない。</dd>

<dt><a href="grep2.c">grep2.c</a></dt>
<dd>問題 8-1の解答例。
-iオプションと-vオプションのついたgrepコマンド。</dd>

<dt><a href="slice.c">slice.c</a></dt>
<dd>問題8-2の解答例。
マッチした部分を出力する。
</dd>
</dl>

## 第10章
<dl>
<dt><a href="ls.c">ls.c</a></dt>
<dd>簡単なlsコマンド。</dd>

<dt><a href="catdir.c">catdir.c</a></dt>
<dd>opendirを使わずディレクトリを読むコマンド。
./catdir . | strings とするとなんとなくlsっぽい表示ができる。</dd>

<dt><a href="mkdir.c">mkdir.c</a></dt>
<dd>簡単なmkdirコマンド。mkdir(2)の使用例。</dd>

<dt><a href="rmdir.c">rmdir.c</a></dt>
<dd>簡単なrmdirコマンド。rmdir(2)の使用例。</dd>

<dt><a href="ln.c">ln.c</a></dt>
<dd>簡単なlnコマンド。link(2)の使用例。</dd>

<dt><a href="symlink.c">symlink.c</a></dt>
<dd>簡単なln -sコマンド。symlink(2)の使用例。</dd>

<dt><a href="rm.c">rm.c</a></dt>
<dd>簡単なrmコマンド。unlink(2)の使用例。</dd>

<dt><a href="mv.c">mv.c</a></dt>
<dd>簡単なmvコマンド。rename(2)の使用例。</dd>

<dt><a href="stat.c">stat.c</a></dt>
<dd>コマンドライン引数で指定されたファイルの付帯情報を表示する。
lstat(2)の使用例。</dd>

<dt><a href="touch.c">touch.c</a></dt>
<dd>簡単なtouchコマンド。utime(2)の使用例。
このコマンドは時刻を更新するだけで、ファイルを作る機能はない。</dd>

<dt><a href="chmod.c">chmod.c</a></dt>
<dd>簡単なchmodコマンド。chmod(2)の使用例。</dd>

<dt><a href="chown.c">chown.c</a></dt>
<dd>簡単なchownコマンド。chown(2)とgetpwnam(3) の使用例。</dd>

<dt><a href="chgrp.c">chgrp.c</a></dt>
<dd>簡単なchgrpコマンド。chgrp(2)の使用例。</dd>

<dt><a href="traverse.c">traverse.c</a></dt>
<dd>問題10-1の解答例。
コマンドライン引数で指定したディレクトリをトラバースして中にあるファイルを表示するプログラム。
</dd>

<dt><a href="mkpath.c">mkpath.c</a></dt>
<dd>問題10-3の解答例。
複数階層のディレクトリツリーを再帰的に作成する。
</dd>
</dl>

## 第11章
<dl>
<dt><a href="mapwrite.c">mapwrite.c</a></dt>
<dd>mmap(2) のテストプログラム。</dd>

<dt><a href="shlib/">shlib/*</a></dt>
<dd>共有ライブラリを作成する例 [Linux only]</dd>

<dt><a href="link/">link/*</a></dt>
<dd>ライブラリのダイナミックリンクとダイナミックロードの例 [Linux only]</dd>

<dt><a href="tail2.c">tail2.c</a></dt>
<dd>問題11-1の解答例。
簡単なtailコマンド（出力行数がコマンドライン引数で指定可能）。</dd>
</dl>

## 第12章
<dl>
<dt><a href="exec.c">exec.c</a></dt>
<dd>exec族のテストコード。</dd>

<dt><a href="spawn.c">spawn.c</a></dt>
<dd>コマンドライン引数で渡されたコマンドを実行する。</dd>

<dt><a href="dupread.c">dupread.c</a></dt>
<dd>dup(2)のテストプログラム。</dd>

<dt><a href="sh1.c">sh1.c</a></dt>
<dd>問題12-2の解答例。
ごく簡単なシェル。</dd>

<dt><a href="sh2.c">sh2.c</a></dt>
<dd>問題12-3の解答例。
パイプとリダイレクトを実装したシェル。</dd>
</dl>

## 第13章
<dl>
<dt><a href="sig.c">sig.c</a></dt>
<dd>signal(2) のテストプログラム。SIGINT を待つだけ。</dd>

<dt><a href="sigqueue-test.c">sigqueue-test.c</a></dt>
<dd>シグナルがキューイングされるかテストするプログラム。
Linux では、プログラムが起動したあとに素早く 5 回
Ctrl-C を打っても (5 回シグナルを送っても) メッセー
ジは 2 回しか表示されない。つまり残り 3 つは失われ
たということ。</dd>

<dt><a href="isatty.c">isatty.c</a></dt>
<dd>stdin, stdout, stderr のそれぞれについて、
端末かどうか判定する。</dd>

<dt><a href="trap.c">trap.c</a></dt>
<dd>問題 13-1 の解答例。
SIGINT (Ctrl-C による割り込み) を受けたらメッセージを
出して終了する。</dd>
</dl>

## 第14章
<dl>
<dt><a href="pwd.c">pwd.c</a></dt>
<dd>簡単なpwdコマンド。定数を使う。</dd>

<dt><a href="pwd2.c">pwd2.c</a></dt>
<dd>簡単なpwdコマンド。自分でバッファの長さを調節する。</dd>

<dt><a href="pwd3.c">pwd3.c</a></dt>
<dd>簡単なpwdコマンド。GNU libc特有のgetcwd()の機能を使う。 [Linux Only]</dd>

<dt><a href="showenv.c">showenv.c</a></dt>
<dd>getenv(3) のテストプログラム。
コマンドライン引数で指定された環境変数の値を表示する。
env.c も参照。</dd>

<dt><a href="env.c">env.c</a></dt>
<dd>簡単なenvコマンド。すべての環境変数を表示する。</dd>

<dt><a href="user.c">user.c</a></dt>
<dd>コマンドライン引数で指定したユーザのユーザ ID を表示する。
getpwnam(3) の使用例。</dd>

<dt><a href="id.c">id.c</a></dt>
<dd>簡単なidコマンド。user.c も参照。</dd>

<dt><a href="timefmt.c">timefmt.c</a></dt>
<dd>時刻 API のテストプログラム。</dd>

<dt><a href="strftime.c">strftime.c</a></dt>
<dd>strftime(3) のテストプログラム。</dd>

<dt><a href="ls2.c">ls2.c</a></dt>
<dd>問題14-3の解答例。
簡単なlsコマンド。ファイルのオーナーと最終更新時刻も表示する。</dd>
</dl>

## 第15章
<dl>
<dt><a href="daytime.c">daytime.c</a></dt>
<dd>daytimeクライアント。</dd>

<dt><a href="daytimed.c">daytimed.c</a></dt>
<dd>daytimeサーバ。
書籍で書いたのと同じ理由によりIPv4専用。</dd>
</dl>

## 第16章
<dl>
<dt><a href="httpd.c">httpd.c</a></dt>
<dd>本章で作成したお手軽HTTPサーバ。
stdinしか読めない。
</dd>
</dl>

## 第17章
<dl>
<dt><a href="httpd2.c">httpd2.c</a></dt>
<dd>本章で作成したお手軽HTTPサーバ。
自分でデーモン化とソケット接続が可能。</dd>

```
$ sudo ./httpd2 --port=8080 --chroot --user=arch --group=users .
$ nc localhost 8080
GET /hello.c HTTP/1.0

HTTP/1.0 200 OK
Date: Mon, 23 Sep 2019 11:09:39 GMT
Server: LittleHTTP/1.0
Connection: close
Content-Length: 104
Content-Type: text/plain

#include <stdio.h>

int main(int argc, char const* argv[])
{
    printf("Hello World");
    return 0;
}
```

<dt><a href="logging.c">logging.c</a></dt>
<dd>syslog(3)のテストプログラム。</dd>
</dl>

## 第18章
<dl>
<dt><a href="make/">make/*</a></dt>
<dd>makeとMakefileの例</dd>
</dl>
