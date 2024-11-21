// Copyright (c) 2009-2015 The Bitcoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef DOGECASH_QT_TEST_PAYMENTREQUESTDATA_H
#define DOGECASH_QT_TEST_PAYMENTREQUESTDATA_H

//
// Data for paymentservertests.cpp
//

// Base64/DER-encoded fake certificate authority certificates.
// Convert pem to base64/der with:
// openssl x509 -in cert.pem -inform PEM -outform DER | openssl enc -base64

// Version: 3
// Serial Number: 6D:8A:62:44:0F:AD:D9:CD:EF:C6:B0:BF:E1:68:1F:19:F0:79:CF:76
// Issuer: CN=PaymentRequest Test CA
// Subject: CN=PaymentRequest Test CA
// Not After : Dec  11  10:52:09 2032 GMT
//
const char *caCert1_BASE64 = "\
MIIC/zCCAeegAwIBAgIUbYpiRA+t2c3vxrC/4WgfGfB5z3YwDQYJKoZIhvcNAQEL\
BQAwITEfMB0GA1UEAwwWUGF5bWVudFJlcXVlc3QgVGVzdCBDQTAeFw0yMjEyMTQx\
MDUyMDlaFw0zMjEyMTExMDUyMDlaMCExHzAdBgNVBAMMFlBheW1lbnRSZXF1ZXN0\
IFRlc3QgQ0EwggEiMA0GCSqGSIb3DQEBAQUAA4IBDwAwggEKAoIBAQCuwzkQnJ9k\
Pi00754JNf+oxcZZSmx8+25vyaV0fbtBO36e4tZcwDLC1nS9Z9PjDfLGJ/ndtA02\
/of6SgK6NAafuj0KpSVA5jcaANfcwbEso2G/ArEI+b5cKG124eLr2SHIpVIvAK0g\
UJW8ppA0mzIjkjuLTpXVGrJBbu05J/CgKj7SxkZHPbg50P/SyQ+C7Fs+X0pga8p9\
QPBFugcF/zZvBpGKxPsBJ7EtZ5xbED9cqWr2/+Ktzac6nih8F9vl3YqZ0ZSTj382\
AevrpO8PhY95zTvkehwndpiLOD0S1GtkPnaGpj74ezOFsmI5jV+bRegmtSflN4e2\
VUcbKBfTaCA9AgMBAAGjLzAtMAwGA1UdEwQFMAMBAf8wHQYDVR0OBBYEFICgp+tR\
grwH/JolJD6z3dauFZWLMA0GCSqGSIb3DQEBCwUAA4IBAQBGiLPMao4SW4IdcyFe\
DTf0PSYrolAe4IPyLvUYlZXuKaGBv9ofhDZSAc7OAGLx5WLij2gi4c8gMi7pSfUN\
I+9XEEEJ5jGM9JFcFjMPkcSX8Xq3eao6DfwBe7T8I7llxn12Fz6c8XTjDCqQ9Rrk\
Yep3Hq9dz+eeh0Zf7SrYhOhqKhhEQK/AnCW7FY+ovjxNryNcgoMIhU2kegd97oSF\
LHpZOnn4tBqI2tQetPC8SEDrYKQw2VetcEjCtl3kBA22dQYRCwbAzh9zL1gAPYXf\
JAnG/l0NUCTV2a2vo9qk9i/7Cq2gdHcA7aLsi56BfVcu8yb7lcRLwQLOnPqlZp//\
AsSc\
";

// Serial Number: f0:da:97:e4:38:d7:64:16
// Issuer: CN=PaymentRequest Test CA
// Subject: CN=PaymentRequest Test CA
// Not Valid After : Jan  8 18:21:06 2025 GMT
//
const char *caCert2_BASE64 = "\
MIIC1TCCAb2gAwIBAgIJAPDal+Q412QWMA0GCSqGSIb3DQEBCwUAMCExHzAdBgNV\
BAMMFlBheW1lbnRSZXF1ZXN0IFRlc3QgQ0EwHhcNMTUwMTExMTgyMTA2WhcNMjUw\
MTA4MTgyMTA2WjAhMR8wHQYDVQQDDBZQYXltZW50UmVxdWVzdCBUZXN0IENBMIIB\
IjANBgkqhkiG9w0BAQEFAAOCAQ8AMIIBCgKCAQEA1S9wVLfTplJuT/1OaaBgl/Mb\
I392v8S9kHbzYz7B4OTMslaO7piz0v3SO3TKMh0dswjiRdHrIgpO7XdIUQiU/ugg\
xDw0kuNehfz1ycaGedlFFtFHTNXqLyIUF3dlwHhQwaomM6RXoJmxLny5BhYHEcmk\
yWwr3Cdjd9gAZpblugVJB9C1e40uyL8ao4PHdLzOqO27iSe6riP8SwwisJZEbMaz\
AZpgNEEMbIXPJEFvm5HTRXSMtQCOTSZYMFF0M2yrtmlECnz7hWP19b9bcoDzZQB4\
ylIsFG/7q2jV7MC/e2STZv+niJiHL08RUdoFpAgzaxMgqj63C7B55HgNDNHJYQID\
AQABoxAwDjAMBgNVHRMEBTADAQH/MA0GCSqGSIb3DQEBCwUAA4IBAQBGejPxLxj9\
+crv6gUeEBMZPiUx7pUgcI22Wm5yymP96B4fwI3Y0DBehq20d76vbWGPN17Z6pH3\
ge7PVY1SYqXtS6hXTo4olCm/BZADli+2Bs2xCiaa+Ltve4ufVej+bKJXN/YnrhvO\
Kq+klQkuuHywU+GJV/NQeBqToIrSOBgi477NgLFCCCmmx2QWsxHoCFGfuRCBVseT\
z2k/tMuALCDXGeZBRPTsGHu1y4cj84swAeoDK5QSQcI+Ub7GKc+zkoj02sdDLiMo\
3wokYPcIy47oclhmb4xubHc+y7nF610yZBoC/zgbhbawnZ65hDDWkdQ/SVAnWZD7\
9PFfmNnYPTQH\
";

//
// This payment request validates directly against the
// caCert1 certificate authority.
//
const char *paymentrequest1_cert1_BASE64 = "\
Egt4NTA5K3NoYTI1Nhq2BgqzBjCCAy8wggIXoAMCAQICAQEwDQYJKoZIhvcNAQELBQAwITEfMB0G\
A1UEAwwWUGF5bWVudFJlcXVlc3QgVGVzdCBDQTAeFw0yMjEyMTQxMDUyMDlaFw0zMjEyMTExMDUy\
MDlaMEMxGTAXBgNVBAMMEHRlc3RtZXJjaGFudC5vcmcxJjAkBgNVBAoMHVBheW1lbnQgUmVxdWVz\
dCBUZXN0IE1lcmNoYW50MIIBIjANBgkqhkiG9w0BAQEFAAOCAQ8AMIIBCgKCAQEAoPhPki8Jgvme\
O2STD9jkcnvvQZn6Y0oMjEC1DKBs813m74/JZwOPLq+zpW8ENRc5WY6l6miOASJhTHLriMdN+rGM\
H5ZkA3yPvo9mW0pG/1hXjjl7IyMXvrhVPWTwk7pxOjd8KjTypgT8q9X4oiyvetFeU7MtQVTs7gJL\
sE3NCybG4oGKjazDoDBcGr8GoAncT8uzU+LI7hq2k8PtNWlMO7E3ujbFnUqhHSCio+pbACsaCJ29\
ZH8VVITsA2mYThUx4RldsDO81W1/3auy1eXgTTQIisf0x5mtw9fvdPV6lK2o7/gBO8PWAiha1hI3\
svxWIXyfO1l1A4E+AgffOtNpkQIDAQABo1AwTjAMBgNVHRMEBTADAQH/MB0GA1UdDgQWBBSygPuN\
tmXqiYAdYbGBrMzih19a2DAfBgNVHSMEGDAWgBSAoKfrUYK8B/yaJSQ+s93WrhWVizANBgkqhkiG\
9w0BAQsFAAOCAQEAjrChYh+Am9MGjYJsGT4Wzv5cFJ39mOqr8JT+wyUY5wmdrHaUN0K/We0EhW9m\
ge3H+BvbyjeHvUIdKc/a3Dby1PyM4iU+2z2TPYcLTqOin79R5VL+20z5yfsfI9wsaa2+oIwoUSOg\
S8duILzyOKMR5VkEaQ+MNQjLPFnAB+bPbk+cEwPxVs9oqzQBMzTskavcQfUYqr0udjJsbCqlQ0z0\
PGm6QPMxctI3NpsGskZPJ+zojuaRNPKA5Tn36Nux4QmuL3T4+gsh961ccN4kmhUqscjxYJ1SYibl\
2hQOt1bvCSfITWlfDLYc0Owd15rrnJf2fhuwIQEm6IUGxUhKk+yX2CIxEiEIgNTb0g8SGXapFO2N\
fiXoI85ijPezGjexnyq3JUqKiKwY7OHmnAYg/42mswcqACqAAgqWKaYGk5Yyii4BRnvPJOvShW3M\
RDnZxdGI2mdqFbUDFY+suSOWUVUnJ9nglVIPHwoEIXb8GeUOcGzwrlKlW5X/pusCGNbOihjxpV8I\
Vg2qPPuCQ7Ersr7/TfazxffaSnZWL3mgnh/Q2FaW8hJVG94f+6woaGRloIgyM6LiHtjSJWNtyT7q\
DfeIWieLLCe3Y1DnN2lWKufEpUZbd7szl+MBIWmapFyLtBVGZ/+fQZeiH08XARU55SwcuMPZS0Sm\
IkGip7u8kQStLOIDn15mSVcQQtMaX56CgLpa3i5/0tyv5tkX2CMWNBuSEZcNmokSe4OEvvIFFwOs\
j89IvXiIrWM=\
";

//
// Signed, but expired, merchant cert in the request
//
const char *paymentrequest2_cert1_BASE64 = "\
Egt4NTA5K3NoYTI1NhrsAwrpAzCCAeUwggFOoAMCAQICAQMwDQYJKoZIhvcNAQEL\
BQAwITEfMB0GA1UEAxMWUGF5bWVudFJlcXVlc3QgVGVzdCBDQTAeFw0xMzAyMjMy\
MTI2NDNaFw0xMzAyMjQyMTI2NDNaMD4xHDAaBgNVBAMME2V4cGlyZWRtZXJjaGFu\
dC5vcmcxHjAcBgNVBAoMFUV4cGlyZWQgVGVzdCBNZXJjaGFudDCBnzANBgkqhkiG\
9w0BAQEFAAOBjQAwgYkCgYEAx5DMvFtbuh7FpUqnVk5jCn+eICAsTX8W2Pq3DLQH\
7a+toQmMdndkIkkXdaQlM5qNdiIkl91sUh8Gk509zBQ+o0cevszOl3RmqyNs6WJX\
tdQDc7uIALYTde7kUB1djuUMVbczWjHSniS109i/bXxHci/vvWVKqEJnQGBvYsd9\
9IUCAwEAAaMQMA4wDAYDVR0TBAUwAwEB/zANBgkqhkiG9w0BAQsFAAOBgQAaU137\
j53rvSjlmYZpZ4RWTP7EdD6fl5ZxBeXHytN6DQL33H0eD7OFHt+ofc7E6D7keubl\
UfCu+jOvt/MvvPUmtCI9yXZ0dNC4sjyETv+wQpxO0UNZwOM4uegdCzlo6Bi3pD4/\
KKLdMkWuUfuPBmoammny74lZaOVr5deKXztTuCI0Eh8IsNsGEhl2qRSVYIoDyPul\
6RMbTSzv4tVhVfGZqIisGLLhxYsFKgtVbml0VGVzdFR3byqAAXHuo4nZEPniLpkd\
y30TkwBxVgprWJ18a9z/7Py35Qss/JMbOXbnBhJtmJCdIowHRI0aa+zqt3KKKAXi\
mm+V4seMgxTcxMS+eDDkiTcB/RtWWSyRcS2ANjFeY0T4SLMwiCL9qWPi03hr8j96\
tejrSPOBNSJ3Mi/q5u2Yl4gJZY2b\
";

//
// 10-long certificate chain, all intermediates valid
//
const char *paymentrequest3_cert1_BASE64 = "\
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\
";

//
// Long certificate chain, with an expired certificate in the middle
//
const char *paymentrequest4_cert1_BASE64 = "\
Egt4NTA5K3NoYTI1NhqeJAr/AzCCAfswggFkoAMCAQICAQEwDQYJKoZIhvcNAQEL\
BQAwPzEUMBIGA1UEAwwLdGVzdGNhOC5vcmcxJzAlBgNVBAoMHlBheW1lbnQgUmVx\
dWVzdCBJbnRlcm1lZGlhdGUgODAeFw0xMzAyMjMyMjQyMzFaFw0yMzAyMjEyMjQy\
MzFaMDYxGjAYBgNVBAMMEXRlc3RtZXJjaGFudDgub3JnMRgwFgYDVQQKDA9UZXN0\
IE1lcmNoYW50IDgwgZ8wDQYJKoZIhvcNAQEBBQADgY0AMIGJAoGBAMMCHA3hiHbS\
TKZ5K9jHRwE8NxkGp3IOx56PDB2diNkldG8XweTcRq7bBm7pdiBt4IVggtfs+6hE\
hDYIOecyoAnVzPFTdvQ7KQdQ/fD9YLe6lk+o0edOqutPMyrxLFjSluXxEQyk7fdt\
URloMMYfp3p1/hFCboA1rAsQ2RW38hR5AgMBAAGjEDAOMAwGA1UdEwQFMAMBAf8w\
DQYJKoZIhvcNAQELBQADgYEAPsdFatnc2RJSpvZsw+nCiPVsllycw5ELglq9vfJz\
nJJucRxgzmqI2iuas1ugwbXn0BEIRLK7vMF/qBzQR6M/nTxttah+KEu+okjps9vJ\
cIyhfTyGPC5xkHaHZ7sG+UHOFhPw0/kXn0x+pbVgBZ5315axqcp1R+DTSj/whMAr\
n0AKiAQwggIEMIIBbaADAgECAgECMA0GCSqGSIb3DQEBCwUAMD8xFDASBgNVBAMM\
C3Rlc3RjYTcub3JnMScwJQYDVQQKDB5QYXltZW50IFJlcXVlc3QgSW50ZXJtZWRp\
YXRlIDcwHhcNMTMwMjIzMjI0MjMxWhcNMjMwMjIxMjI0MjMxWjA/MRQwEgYDVQQD\
DAt0ZXN0Y2E4Lm9yZzEnMCUGA1UECgweUGF5bWVudCBSZXF1ZXN0IEludGVybWVk\
aWF0ZSA4MIGfMA0GCSqGSIb3DQEBAQUAA4GNADCBiQKBgQDexUFfxb1sThvabp7u\
dZz59ciThGmmAW0nP4tjrgEACgvWIInr2dZpTHbiQNF34ycsk0le1JD93D7Qb8rd\
25OrpaO8XS2Li2zjR9cleixXjSLwV/zv8zJ8yPl/27XL++PDTKBXVpJ8/Syp+9Ty\
plV1BqDhqtIHb/QSHEkTQXjeYQIDAQABoxAwDjAMBgNVHRMEBTADAQH/MA0GCSqG\
SIb3DQEBCwUAA4GBACMooQVbkbIZ2DaPwHDc4ULwguG3VI2Kzj50UdExmHtzm2S4\
MQei+n+HEPjtJAx5OY520+10nfuP+12H2DRLQmWmdvDpeQ/Cv0yavlw4ZRejRFo7\
KS83C0wo5rd+qTvvOmAN4UTArWkzYcEUulPdiXnRamb0WQHTeVdIbHVkMormCogE\
MIICBDCCAW2gAwIBAgIBAjANBgkqhkiG9w0BAQsFADA/MRQwEgYDVQQDDAt0ZXN0\
Y2E2Lm9yZzEnMCUGA1UECgweUGF5bWVudCBSZXF1ZXN0IEludGVybWVkaWF0ZSA2\
MB4XDTEzMDIyMzIyNDIzMVoXDTIzMDIyMTIyNDIzMVowPzEUMBIGA1UEAwwLdGVz\
dGNhNy5vcmcxJzAlBgNVBAoMHlBheW1lbnQgUmVxdWVzdCBJbnRlcm1lZGlhdGUg\
NzCBnzANBgkqhkiG9w0BAQEFAAOBjQAwgYkCgYEAtjBRazrkebXAhXsbjimrMIRm\
W/f9SwAHwXfc042keNtl0t2z6XE6UPcR2v/KrssXuCZgodeYxz6IM6lWosCM1xot\
C3ChKKFBfVO30reuKBRUxXfKAFqxaG0YOAEzdZkkY9AGhqWloeSmgxpIfhInU0EF\
JjCwrJ6IkijBatGoAAECAwEAAaMQMA4wDAYDVR0TBAUwAwEB/zANBgkqhkiG9w0B\
AQsFAAOBgQDBRTi1MolmOA0niHYX0A2lN5QWHkCfX0A7GwyoMA3dvM45m/NYd4WB\
X+HwfnfYcI6X9jOgNo5OWmc4GGsld0HlxwMYEKISBS9PbSHPBrb3TBOlw5ztQpXZ\
91+bOhLux52Fr03sK7v9qExmBM12M8UR2ltpzAMiUgLLMHyPfiWkvQqIBDCCAgQw\
ggFtoAMCAQICAQIwDQYJKoZIhvcNAQELBQAwPzEUMBIGA1UEAwwLdGVzdGNhNS5v\
cmcxJzAlBgNVBAoMHlBheW1lbnQgUmVxdWVzdCBJbnRlcm1lZGlhdGUgNTAeFw0x\
MzAyMjMyMjQyMzBaFw0yMzAyMjEyMjQyMzBaMD8xFDASBgNVBAMMC3Rlc3RjYTYu\
b3JnMScwJQYDVQQKDB5QYXltZW50IFJlcXVlc3QgSW50ZXJtZWRpYXRlIDYwgZ8w\
DQYJKoZIhvcNAQEBBQADgY0AMIGJAoGBANJSH3xivX1t9olIdHsznI1aE9SD7t9i\
SZJsIB0otoETHZRVv9M9LvyzBNK98ZV+kTOlST7PJgC0d9BQM9sgYApSRq5oqKDM\
9FXbOm/yaReAbU3mkFNFw5roTlJ5ThEy0yOGT/DS0YBRaGIvRPRj2DiqDVdCZZ+w\
4jo1IYHkZt4FAgMBAAGjEDAOMAwGA1UdEwQFMAMBAf8wDQYJKoZIhvcNAQELBQAD\
gYEATm6+J1OmbrothO60xALKonWMBKr6hudb4amkFBqKbA9wMeM3jl+I/yKfz/Uf\
xWuJ071IhiNv6Gxx5YwNvhUe1xMhUqHv0gpyK1Z47bD+kYS2se5sWNPNo3Y9qZDG\
IXiGQxwHmrzaFk79Uy1xsmvsEz42w6hr25Yaw7HkIgrFveoK6gMwggHmMIIBT6AD\
AgECAgEGMA0GCSqGSIb3DQEBCwUAMCExHzAdBgNVBAMTFlBheW1lbnRSZXF1ZXN0\
IFRlc3QgQ0EwHhcNMTMwMjIzMjI1OTUxWhcNMTMwMjI0MjI1OTUxWjA/MRQwEgYD\
VQQDDAt0ZXN0Y2E1Lm9yZzEnMCUGA1UECgweUGF5bWVudCBSZXF1ZXN0IEludGVy\
bWVkaWF0ZSA1MIGfMA0GCSqGSIb3DQEBAQUAA4GNADCBiQKBgQC7vVUFpxHzz2Tr\
/xij3k58s8d/BPA0R6D5RXTVvmhAzc1Zuin4zUKRFs/aCj/0yED8Wu/COfNGF4tV\
lRNMdl9EcFsxa8XGEL4eAZa+H/rOHH+7/1EINrrVWhZlUecyhilN8jmCZmqEM3ec\
uD0NAViqyMrgmaiFmsLoQZpEGepDUQIDAQABoxAwDjAMBgNVHRMEBTADAQH/MA0G\
CSqGSIb3DQEBCwUAA4GBAEmcUEnhua/oiXy1fwScLgMqt+jk9mHRpE6SVsIop23Q\
CY2JfpG6RxhMMzzzhGklEGN6cxG0HCi6B3HJx6PYrFEfTB0rW4K6m0Tvx3WpS9mN\
uoEuJHLy18ausI/sYAPDHCL+SfBVcqorpaIG2sSpZouRBjRHAyqFAYlwlW87uq5n\
CogEMIICBDCCAW2gAwIBAgIBAjANBgkqhkiG9w0BAQsFADA/MRQwEgYDVQQDDAt0\
ZXN0Y2EzLm9yZzEnMCUGA1UECgweUGF5bWVudCBSZXF1ZXN0IEludGVybWVkaWF0\
ZSAzMB4XDTEzMDIyMzIyNDIyOVoXDTIzMDIyMTIyNDIyOVowPzEUMBIGA1UEAwwL\
dGVzdGNhNC5vcmcxJzAlBgNVBAoMHlBheW1lbnQgUmVxdWVzdCBJbnRlcm1lZGlh\
dGUgNDCBnzANBgkqhkiG9w0BAQEFAAOBjQAwgYkCgYEAxYYo3w2UXiYg6O8b4Qgw\
N/vgreTkiW122Ep/z2TiDrhVMhfOOiKdwYESPflfnXnVaQQzCGexYTQqsvqvzHSy\
na5hL0zPTRJxSKmTVrXRsWtpdCRhjxCGipS3tlQBDi7vb+7SNRIBK4dBjjGzALNk\
7gMCpy+yM8f6I043jTlmGb0CAwEAAaMQMA4wDAYDVR0TBAUwAwEB/zANBgkqhkiG\
9w0BAQsFAAOBgQDU+IQxt3OhKqaUYWC23+cB2gekvWqwMBnrCNrX/Dp+kjoJKUoR\
2Fs3qw53raHES4SIhpGT9l9lrppNQgFe/JMHeYqOZMZO+6kuU0olJanBJ14tPIc7\
zlMTQ9OfmZ6v07IpyFbsQDtRhpe80DpuvSFPfJ4fh0WrQf6kn3KDVpGDnAqIBDCC\
AgQwggFtoAMCAQICAQIwDQYJKoZIhvcNAQELBQAwPzEUMBIGA1UEAwwLdGVzdGNh\
Mi5vcmcxJzAlBgNVBAoMHlBheW1lbnQgUmVxdWVzdCBJbnRlcm1lZGlhdGUgMjAe\
Fw0xMzAyMjMyMjQyMjlaFw0yMzAyMjEyMjQyMjlaMD8xFDASBgNVBAMMC3Rlc3Rj\
YTMub3JnMScwJQYDVQQKDB5QYXltZW50IFJlcXVlc3QgSW50ZXJtZWRpYXRlIDMw\
gZ8wDQYJKoZIhvcNAQEBBQADgY0AMIGJAoGBANzgVP99Qg98e6NsKEz1v5KqRB7N\
TBRRsYnBvb/TSWipvMQaCYuEyk1xG57x++QuASKeR3QHRQJOoAhQaj9JLUhSSv9G\
Q5PrFLLsOFv7L1tpzXHh2dOBIW92X2yFRW2s39q+Q21yvN+N8uoKdqXhzRA+dDoX\
h3cavaVeHX1G+IrlAgMBAAGjEDAOMAwGA1UdEwQFMAMBAf8wDQYJKoZIhvcNAQEL\
BQADgYEASTwg84cX+1UhOG9sejFV3m34QuI1hPZ+qhqVJlRYUtego8Wng1BburDS\
wqVAv4ch2wi3c2s4e8J7AXyLtzSbSQG4RN0oZi0mR8EtTTN+Mix/hBIk79dMZg85\
+I29uFA6Zj2d9oAhQv2qkHhc6tcaheNvkQRlCyH68k3iF1Fqf+4KiAQwggIEMIIB\
baADAgECAgECMA0GCSqGSIb3DQEBCwUAMD8xFDASBgNVBAMMC3Rlc3RjYTEub3Jn\
MScwJQYDVQQKDB5QYXltZW50IFJlcXVlc3QgSW50ZXJtZWRpYXRlIDEwHhcNMTMw\
MjIzMjI0MjI5WhcNMjMwMjIxMjI0MjI5WjA/MRQwEgYDVQQDDAt0ZXN0Y2EyLm9y\
ZzEnMCUGA1UECgweUGF5bWVudCBSZXF1ZXN0IEludGVybWVkaWF0ZSAyMIGfMA0G\
CSqGSIb3DQEBAQUAA4GNADCBiQKBgQDaV8zhfyQuSf/f+fauMfgs3g/RnWy9yxxU\
kvQneQQPH3uZzCyk3A6q72ipTtwNqiibG9455L9A7SaUjGtnpUz0NKT/VWUdqbfC\
l1PqXjEZbDobbAQ5hxLGOTyLRQhLIcgeq2/BnmeCqHsC4md04nUp+nBo1HwKyygv\
K+9sMbCp/wIDAQABoxAwDjAMBgNVHRMEBTADAQH/MA0GCSqGSIb3DQEBCwUAA4GB\
ACvYyE+PPmWFkbjyRu9LAt8DcrtyYYLRClKSg6tVvutwukLG2l//kDOohYkJtgTq\
r6LnCIIIwYdXN+4wxugmw4cnPIZmP6kovxjhhVM95okilor1zniTAo3RN7JDIfTG\
NgxLdGu1btt7DOFL4zTbeSJMb8M1JpPftehH+x/VLyuUCuoDMIIB5jCCAU+gAwIB\
AgIBBTANBgkqhkiG9w0BAQsFADAhMR8wHQYDVQQDExZQYXltZW50UmVxdWVzdCBU\
ZXN0IENBMB4XDTEzMDIyMzIyNDIyOFoXDTIzMDIyMTIyNDIyOFowPzEUMBIGA1UE\
AwwLdGVzdGNhMS5vcmcxJzAlBgNVBAoMHlBheW1lbnQgUmVxdWVzdCBJbnRlcm1l\
ZGlhdGUgMTCBnzANBgkqhkiG9w0BAQEFAAOBjQAwgYkCgYEAo5Vy9H3nA/OOkF5A\
p89yfVNSiTay/LYCaB0eALpcU690U75O9Q3w2M+2AN8wpbbHsJHZMIjEeBRoQfjl\
YXW1ucQTxWKyT+liu0D25mGXX27CBXBd4iXTxVII/iX+u3lcjORjoHOBy7QgeIDI\
IS9y0vYu8eArpjh7m4thrVgIRtMCAwEAAaMQMA4wDAYDVR0TBAUwAwEB/zANBgkq\
hkiG9w0BAQsFAAOBgQB9LKcVJK9sjASNzpQlpUp7nCiw5FSjVY+XMRIKK/kavzlK\
jZ+InsmmyRVGjDoZi9GrqG9PVHgLBxi2VtVjmokZoNPqao3OfhqORAubC+JR/JLe\
pM7aDaxDdTHVhSUk4lgNAvi26dGY7nZMsnHlPQ2tPp/HvRRiMq1oDjlylc8VTCI1\
Eh8IsNsGEhl2qRSVYIoDyPul6RMbTSzv4tVhVfGZqIisGLLhxYsFKgxVbml0VGVz\
dEZvdXIqgAEBE1PP93Tkpif35F+dYmXn9kLA/1djcPjCs2o2rwRMM4Uk356O5dgu\
HXQjsfdR58qZQS9CS5DAtRUf0R8+43/wijO/hb49VNaNXmY+/cPHMkahP2aV3tZi\
FAyZblLik9A7ZvF+UsjeFQiHB5wzWQvbqk5wQ4yabHIXoYv/E0q+eQ==\
";

//
// Validly signed, but by a CA not in our root CA list
//
const char *paymentrequest5_cert1_BASE64 = "\
Egt4NTA5K3NoYTI1NhrxAwruAzCCAeowggFToAMCAQICAQEwDQYJKoZIhvcNAQEL\
BQAwITEfMB0GA1UEAxMWUGF5bWVudFJlcXVlc3QgVGVzdCBDQTAeFw0xMzA0MTkx\
NzIwMDZaFw0yMzA0MTcxNzIwMDZaMEMxGTAXBgNVBAMMEHRlc3RtZXJjaGFudC5v\
cmcxJjAkBgNVBAoMHVBheW1lbnQgUmVxdWVzdCBUZXN0IE1lcmNoYW50MIGfMA0G\
CSqGSIb3DQEBAQUAA4GNADCBiQKBgQDhV6Yn47aEEmbl50YLvXoqGEJA51I/40wr\
Z6VQGdXYaRqYktagrWDlgYY9h0JQ1bQhm8HgW7ju0R4NaDTXUqxg4HjprF0z3Mfm\
/6mmebkLOOptfkVD7ceAteNI7cyuqWGIAZA7D9mV97mXoCAtTlBUycvkmoiClCCS\
h0EpF/UTaQIDAQABoxAwDjAMBgNVHRMEBTADAQH/MA0GCSqGSIb3DQEBCwUAA4GB\
AGIRwW7I0QvLga+RnJoJSZNZQbtu4rQW3xmoz8WfZMBYXX3QBYg5ftycbdK+/IbP\
qozfjGW2AS6DNArvpveSPDTK9+GJBNo1paiNtVqwXkC3Ddscv5AIms1eZGiIOQNC\
mUvdLkpoXo48WAer3EGsZ3B15GyNEELc0q9W5yUebba1IjUSHwiw2wYSGXapFJVg\
igPI+6XpExtNLO/i1WFV8ZmoiKwYuPvFiwUqDFVuaXRUZXN0Rml2ZSqAAXdsMgdG\
ssymvca1S/1KeM3n8Ydi2fi1JUzAAr59xPvNJRUeqCLP9upHn5z7br3P12Oz9A20\
5/4wL4ClPRPVnOHgij0bEg+y0tGESqmF1rfOfXDszlo2U92wCxS07kq79YAZJ1Zo\
XYh860/Q4wvc7lfiTe+dXBzPKAKhMy91yETY\
";

//
// Contains a testnet paytoaddress, so payment request network doesn't match
// client network
//
const char *paymentrequest1_cert2_BASE64 = "\
Egt4NTA5K3NoYTI1NhrQBArNBDCCAkkwggExoAMCAQICAQEwDQYJKoZIhvcNAQEL\
BQAwITEfMB0GA1UEAwwWUGF5bWVudFJlcXVlc3QgVGVzdCBDQTAeFw0xNTAxMTEx\
ODIxMDhaFw0yNTAxMDgxODIxMDhaMCExHzAdBgNVBAMMFlBheW1lbnRSZXF1ZXN0\
IFRlc3QgQ0EwgZ8wDQYJKoZIhvcNAQEBBQADgY0AMIGJAoGBAMsZqzkzeBGo+i2N\
mUak3Ciodr1V7S062VOy7N0OQYNDQHYkgDFAUET7cEb5VJaHPv5m3ppTBpU9xBcf\
wbHHUt4VjA+mhRmYrl1khjvZM+X8kEqvWn20BtcM9R6r0yIYec8UERDDHBleL/P8\
RkxEnVLjYTV9zigCXfMsgYb3EQShAgMBAAGjEDAOMAwGA1UdEwQFMAMBAf8wDQYJ\
KoZIhvcNAQELBQADggEBABUJpl3QCqsoDSxAsQdV6zKT4VGV76AzoGj7etQsQY+r\
+S26VfWh/fMobEzuxFChr0USgLJ6FoK78hAtoZvt1lrye9yqFv/ig3WLWsJKWHHb\
3RT6oR03CIwZXFSUasi08QDVLxafwsU5OMcPLucF3a1lRL1ccYrNgVCCx1+X7Bos\
tIgDGRQQ4AyoHTcfVd2hEGeUv7k14mOxFsAp6851yosHq9Q2kwmdH+rHEJbjof87\
yyKLagc4owyXBZYkQmkeHWCNqnuRmO5vUsfVb0UUrkD64o7Th/NjwooA7SCiUXl6\
dfygT1b7ggpx7GC+sP2DsIM47IAZ55drjqX5u2f+Ba0iPQoEdGVzdBIhCIDWwowE\
Ehl2qRQErGqUUwSsaMpDvWIaGnJGNQqi8oisGNeMy6UFKgxKdXN0IFRlc3Rpbmcq\
gAFwThsozZxkZxzCn4R8WxNiLFV6m0ye9fEtSbolfaW+EjBMpO03lr/dwNnrclhg\
ew+A05xfZztrAt16XKEY7qKJ/eY2nLd0fVAIu/nIt+7/VYVXT83zLrWc150aRS7W\
AdJbL3JOJLs6Eyp5zrPbfI8faRttFAdONKDrJgIpuW1E3g==\
";

//
// Expired payment request (expires is set to 1 = 1970-01-01 00:00:01)
//
const char *paymentrequest2_cert2_BASE64 = "\
Egt4NTA5K3NoYTI1NhrQBArNBDCCAkkwggExoAMCAQICAQEwDQYJKoZIhvcNAQEL\
BQAwITEfMB0GA1UEAwwWUGF5bWVudFJlcXVlc3QgVGVzdCBDQTAeFw0xNTAxMTEx\
ODIxMDhaFw0yNTAxMDgxODIxMDhaMCExHzAdBgNVBAMMFlBheW1lbnRSZXF1ZXN0\
IFRlc3QgQ0EwgZ8wDQYJKoZIhvcNAQEBBQADgY0AMIGJAoGBAMsZqzkzeBGo+i2N\
mUak3Ciodr1V7S062VOy7N0OQYNDQHYkgDFAUET7cEb5VJaHPv5m3ppTBpU9xBcf\
wbHHUt4VjA+mhRmYrl1khjvZM+X8kEqvWn20BtcM9R6r0yIYec8UERDDHBleL/P8\
RkxEnVLjYTV9zigCXfMsgYb3EQShAgMBAAGjEDAOMAwGA1UdEwQFMAMBAf8wDQYJ\
KoZIhvcNAQELBQADggEBABUJpl3QCqsoDSxAsQdV6zKT4VGV76AzoGj7etQsQY+r\
+S26VfWh/fMobEzuxFChr0USgLJ6FoK78hAtoZvt1lrye9yqFv/ig3WLWsJKWHHb\
3RT6oR03CIwZXFSUasi08QDVLxafwsU5OMcPLucF3a1lRL1ccYrNgVCCx1+X7Bos\
tIgDGRQQ4AyoHTcfVd2hEGeUv7k14mOxFsAp6851yosHq9Q2kwmdH+rHEJbjof87\
yyKLagc4owyXBZYkQmkeHWCNqnuRmO5vUsfVb0UUrkD64o7Th/NjwooA7SCiUXl6\
dfygT1b7ggpx7GC+sP2DsIM47IAZ55drjqX5u2f+Ba0iQgoEdGVzdBIgCICt4gQS\
GXapFASsapRTBKxoykO9YhoackY1CqLyiKwYiNLUpQUgASoQVGVzdGluZyB0ZXN0\
bmV0ISqAATXq9A5nmJgtmee/bQTeHeif4w1YYFPBlKghwx6qbVgXTWnwBJtOQhhV\
sZdzbTl95ENR7/Y7VJupW9kDWobCK7zUUhLAzUlwmLlcx6itHw8LTUF5HK+AwsZm\
Zs85lISGvOS0NZW/ENa6l+oQRnL87oqVZr/EDGiuqjz6T0ThQi0l\
";

//
// Unexpired payment request (expires is set to 0x7FFFFFFFFFFFFFFF = max.
// int64_t)
//
const char *paymentrequest3_cert2_BASE64 = "\
Egt4NTA5K3NoYTI1NhrQBArNBDCCAkkwggExoAMCAQICAQEwDQYJKoZIhvcNAQEL\
BQAwITEfMB0GA1UEAwwWUGF5bWVudFJlcXVlc3QgVGVzdCBDQTAeFw0xNTAxMTEx\
ODIxMDhaFw0yNTAxMDgxODIxMDhaMCExHzAdBgNVBAMMFlBheW1lbnRSZXF1ZXN0\
IFRlc3QgQ0EwgZ8wDQYJKoZIhvcNAQEBBQADgY0AMIGJAoGBAMsZqzkzeBGo+i2N\
mUak3Ciodr1V7S062VOy7N0OQYNDQHYkgDFAUET7cEb5VJaHPv5m3ppTBpU9xBcf\
wbHHUt4VjA+mhRmYrl1khjvZM+X8kEqvWn20BtcM9R6r0yIYec8UERDDHBleL/P8\
RkxEnVLjYTV9zigCXfMsgYb3EQShAgMBAAGjEDAOMAwGA1UdEwQFMAMBAf8wDQYJ\
KoZIhvcNAQELBQADggEBABUJpl3QCqsoDSxAsQdV6zKT4VGV76AzoGj7etQsQY+r\
+S26VfWh/fMobEzuxFChr0USgLJ6FoK78hAtoZvt1lrye9yqFv/ig3WLWsJKWHHb\
3RT6oR03CIwZXFSUasi08QDVLxafwsU5OMcPLucF3a1lRL1ccYrNgVCCx1+X7Bos\
tIgDGRQQ4AyoHTcfVd2hEGeUv7k14mOxFsAp6851yosHq9Q2kwmdH+rHEJbjof87\
yyKLagc4owyXBZYkQmkeHWCNqnuRmO5vUsfVb0UUrkD64o7Th/NjwooA7SCiUXl6\
dfygT1b7ggpx7GC+sP2DsIM47IAZ55drjqX5u2f+Ba0iSgoEdGVzdBIgCICt4gQS\
GXapFASsapRTBKxoykO9YhoackY1CqLyiKwYyNfZpQUg//////////9/KhBUZXN0\
aW5nIHRlc3RuZXQhKoABNwi8WnMW4aMvbmvorTiiWJLFhofLFnsoWCJnj3rWLnLh\
n3w6q/fZ26p50ERL/noxdTUfeFsKnlECkUu/fOcOrqyYDiwvxI0SZ034DleVyFU1\
Z3T+X0zcL8oe7bX01Yf+s2V+5JXQXarKnKBrZCGgv2ARjFNSZe7E7vGg5K4Q6Q8=\
";

//
// Unexpired payment request (expires is set to 0x8000000000000000 > max.
// int64_t, allowed uint64)
//
const char *paymentrequest4_cert2_BASE64 = "\
Egt4NTA5K3NoYTI1NhrQBArNBDCCAkkwggExoAMCAQICAQEwDQYJKoZIhvcNAQEL\
BQAwITEfMB0GA1UEAwwWUGF5bWVudFJlcXVlc3QgVGVzdCBDQTAeFw0xNTAxMTEx\
ODIxMDhaFw0yNTAxMDgxODIxMDhaMCExHzAdBgNVBAMMFlBheW1lbnRSZXF1ZXN0\
IFRlc3QgQ0EwgZ8wDQYJKoZIhvcNAQEBBQADgY0AMIGJAoGBAMsZqzkzeBGo+i2N\
mUak3Ciodr1V7S062VOy7N0OQYNDQHYkgDFAUET7cEb5VJaHPv5m3ppTBpU9xBcf\
wbHHUt4VjA+mhRmYrl1khjvZM+X8kEqvWn20BtcM9R6r0yIYec8UERDDHBleL/P8\
RkxEnVLjYTV9zigCXfMsgYb3EQShAgMBAAGjEDAOMAwGA1UdEwQFMAMBAf8wDQYJ\
KoZIhvcNAQELBQADggEBABUJpl3QCqsoDSxAsQdV6zKT4VGV76AzoGj7etQsQY+r\
+S26VfWh/fMobEzuxFChr0USgLJ6FoK78hAtoZvt1lrye9yqFv/ig3WLWsJKWHHb\
3RT6oR03CIwZXFSUasi08QDVLxafwsU5OMcPLucF3a1lRL1ccYrNgVCCx1+X7Bos\
tIgDGRQQ4AyoHTcfVd2hEGeUv7k14mOxFsAp6851yosHq9Q2kwmdH+rHEJbjof87\
yyKLagc4owyXBZYkQmkeHWCNqnuRmO5vUsfVb0UUrkD64o7Th/NjwooA7SCiUXl6\
dfygT1b7ggpx7GC+sP2DsIM47IAZ55drjqX5u2f+Ba0iSwoEdGVzdBIgCICt4gQS\
GXapFASsapRTBKxoykO9YhoackY1CqLyiKwYt+HZpQUggICAgICAgICAASoQVGVz\
dGluZyB0ZXN0bmV0ISqAAXSQG8+GFA18VaKarlYrOz293rNMIub0swKGcQm8jAGX\
HSLaRgHfUDeEPr4hydy4dtfu59KNwe2xsHOHu/SpO4L8SrA4Dm9A7SlNBVWdcLbw\
d2hj739GDLz0b5KuJ2SG6VknMRQM976w/m2qlq0ccVGaaZ2zMIGfpzL3p6adwx/5\
";

//
// Payment request with amount overflow (amount is set to
// 10,000,000,001 DOGE)
// Note: Signature is unchecked (and signs 21M+1 DOGE)
//
const char *paymentrequest5_cert2_BASE64 = "\
Egt4NTA5K3NoYTI1NhrQBArNBDCCAkkwggExoAMCAQICAQEwDQYJKoZIhvcNAQEL\
BQAwITEfMB0GA1UEAwwWUGF5bWVudFJlcXVlc3QgVGVzdCBDQTAeFw0xNTAxMTEx\
ODIxMDhaFw0yNTAxMDgxODIxMDhaMCExHzAdBgNVBAMMFlBheW1lbnRSZXF1ZXN0\
IFRlc3QgQ0EwgZ8wDQYJKoZIhvcNAQEBBQADgY0AMIGJAoGBAMsZqzkzeBGo+i2N\
mUak3Ciodr1V7S062VOy7N0OQYNDQHYkgDFAUET7cEb5VJaHPv5m3ppTBpU9xBcf\
wbHHUt4VjA+mhRmYrl1khjvZM+X8kEqvWn20BtcM9R6r0yIYec8UERDDHBleL/P8\
RkxEnVLjYTV9zigCXfMsgYb3EQShAgMBAAGjEDAOMAwGA1UdEwQFMAMBAf8wDQYJ\
KoZIhvcNAQELBQADggEBABUJpl3QCqsoDSxAsQdV6zKT4VGV76AzoGj7etQsQY+r\
+S26VfWh/fMobEzuxFChr0USgLJ6FoK78hAtoZvt1lrye9yqFv/ig3WLWsJKWHHb\
3RT6oR03CIwZXFSUasi08QDVLxafwsU5OMcPLucF3a1lRL1ccYrNgVCCx1+X7Bos\
tIgDGRQQ4AyoHTcfVd2hEGeUv7k14mOxFsAp6851yosHq9Q2kwmdH+rHEJbjof87\
yyKLagc4owyXBZYkQmkeHWCNqnuRmO5vUsfVb0UUrkD64o7Th/NjwooA7SCiUXl6\
dfygT1b7ggpx7GC+sP2DsIM47IAZ55drjqX5u2f+Ba0iTQoEdGVzdBIlCIDC5+q6\
1q3wDRIZdqkUBKxqlFMErGjKQ71iGhpyRjUKovKIrBi83KymBSoYVGVzdGluZyBh\
bW91bnQgb3ZlcmZsb3chKoABvEu1hA1AurQi+qtgkwY6KfwIrYBMt9US/SKmK7sr\
UYhARVKwQyWVPlBHsxsK+/86BAo6OWWNz5rWXDNrCCzY8sHiRel1cxqk8VMOqTer\
Fl0dk9xsti80b4VQNuUIBqqc9P47ktgbZjW7GT5DfYDDMCopoM3Pj7gs5hCsDyvX\
EGE=\
";

#endif // DOGECASH_QT_TEST_PAYMENTREQUESTDATA_H
