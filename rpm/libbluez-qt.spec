# 
# Do NOT Edit the Auto-generated Part!
# Generated by: spectacle version 0.25
# 

Name:       libbluez-qt

# >> macros
# << macros

Summary:    Library for accessing bluetooth functionality in Qt
Version:    0.1.17
Release:    1
Group:      System/GUI/Other
License:    Apache License 2.0
URL:        https://github.com/nemomobile/libbluez-qt
Source0:    libbluez-qt-%{version}.tar.bz2
Source100:  libbluez-qt.yaml
Requires(post): /sbin/ldconfig
Requires(postun): /sbin/ldconfig
BuildRequires:  pkgconfig(QtCore) >= 4.6.0
BuildRequires:  pkgconfig(QtDBus)
BuildRequires:  pkgconfig(QtOpenGL)
BuildRequires:  pkgconfig(QtGui)
BuildRequires:  pkgconfig(dbus-1)
BuildRequires:  doxygen

%description
This is a library for accessing bluetooth through bluez functionality in Qt.


%package devel
Summary:    Development files for bluez-qt
Group:      Development/Libraries
Requires:   %{name} = %{version}-%{release}

%description devel
This package contains the files necessary to develop
applications using qt to access bluetooth devices using bluez



%prep
%setup -q -n %{name}-%{version}

# >> setup
# << setup

%build
# >> build pre
# << build pre

%qmake 

make %{?jobs:-j%jobs}

# >> build post
# << build post

%install
rm -rf %{buildroot}
# >> install pre
# << install pre
%qmake_install

# >> install post
# << install post


%post -p /sbin/ldconfig

%postun -p /sbin/ldconfig

%files
%defattr(-,root,root,-)
%{_libdir}/libbluez-qt.so.*
%{_libdir}/qt4/imports/Bluetooth/*
%{_sysconfdir}/dbus-1/system.d/bluez-qt.conf
# >> files
# << files

%files devel
%defattr(-,root,root,-)
%{_includedir}/bluez-qt/*.h
%{_libdir}/libbluez-qt.so
%{_libdir}/*.prl
%{_libdir}/pkgconfig/*.pc
%{_libdir}/*.pc
# >> files devel
# << files devel
