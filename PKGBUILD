pkgname=fileinfo
pkgver=1.3
pkgrel=1
pkgdesc="Simply get any file informations with just one command"
arch=('any')
url="https://www.github.com/bomboclaat954/fileinfo"
license=('GPL')
source=("fileinfo.cpp")
sha256sums=("23eb959ad565a53552f4d881dca7c49da17fa4e1a5d77d6efe1cec2c4cea2501")
build() {
    g++ -o fileinfo fileinfo.cpp -w
}
package() {
    install -Dm755 fileinfo "${pkgdir}/usr/bin/fileinfo"
}
