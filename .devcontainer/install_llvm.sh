VERSION=17
wget https://apt.llvm.org/llvm.sh \
&& chmod +x llvm.sh \
&& sudo ./llvm.sh $VERSION all

sudo ln -s -f /usr/bin/clang-$VERSION /usr/bin/clang
sudo ln -s -f /usr/bin/clang++-$VERSION /usr/bin/clang++
sudo ln -s -f /usr/bin/clang-apply-replacements-$VERSION /usr/bin/clang-apply-replacements
sudo ln -s -f /usr/bin/clang-change-namespace-$VERSION /usr/bin/clang-change-namespace
sudo ln -s -f /usr/bin/clang-check-$VERSION /usr/bin/clang-check
sudo ln -s -f /usr/bin/clang-cl-$VERSION /usr/bin/clang-cl
sudo ln -s -f /usr/bin/clang-check-$VERSION /usr/bin/clang-check
sudo ln -s -f /usr/bin/clang-cpp-$VERSION /usr/bin/clang-cpp
sudo ln -s -f /usr/bin/clang-doc-$VERSION /usr/bin/clang-doc
sudo ln -s -f /usr/bin/clang-extdef-mapping-$VERSION /usr/bin/clang-extdef-mapping
sudo ln -s -f /usr/bin/clang-format-$VERSION /usr/bin/clang-format
sudo ln -s -f /usr/bin/clang-format-diff-$VERSION /usr/bin/clang-format-diff
sudo ln -s -f /usr/bin/clang-include-cleaner-$VERSION /usr/bin/clang-include-cleaner
sudo ln -s -f /usr/bin/clang-linker-wrapper-$VERSION /usr/bin/clang-linker-wrapper
sudo ln -s -f /usr/bin/clang-move-$VERSION /usr/bin/clang-move
sudo ln -s -f /usr/bin/clang-offload-bundler-$VERSION /usr/bin/clang-offload-bundler
sudo ln -s -f /usr/bin/clang-offload-packager-$VERSION /usr/bin/clang-packager
sudo ln -s -f /usr/bin/clang-pseudo-$VERSION /usr/bin/clang-pseudo
sudo ln -s -f /usr/bin/clang-query-$VERSION /usr/bin/clang-query
sudo ln -s -f /usr/bin/clang-refactor-$VERSION /usr/bin/clang-refactor
sudo ln -s -f /usr/bin/clang-rename-$VERSION /usr/bin/clang-rename
sudo ln -s -f /usr/bin/clang-reorder-fields-$VERSION /usr/bin/clang-reorder-fields
sudo ln -s -f /usr/bin/clang-repl-$VERSION /usr/bin/clang-repl
sudo ln -s -f /usr/bin/clang-scan-deps-$VERSION /usr/bin/clang-scan-deps
sudo ln -s -f /usr/bin/clang-tblgen-$VERSION /usr/bin/clang-tblgen
sudo ln -s -f /usr/bin/clang-tidy-$VERSION /usr/bin/clang-tidy
sudo ln -s -f /usr/bin/clang-tidy-diff-$VERSION.py /usr/bin/clang-tidy-diff.py
sudo ln -s -f /usr/bin/clangd-$VERSION /usr/bin/clangd
