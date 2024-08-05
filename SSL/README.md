# SSL

## Combine all certificates up to root (chain)

Intermediate/chain certificate to link it to a trusted root certificate

```
cat some.crt another.crt root.crt > CA_bundle.crt
```

```
-----BEGIN CERTIFICATE-----
............................
-----END CERTIFICATE-----
-----BEGIN CERTIFICATE-----
............................
-----END CERTIFICATE-----
-----BEGIN CERTIFICATE-----
............................
-----END CERTIFICATE-----
```

## Convert SSL certificate into PFX

```
openssl pkcs12 -export -out certificate.pfx -inkey privatekey.key -in certificate.crt -certfile CA_bundle.crt
```

## Useful links

[SSL-Checker](https://www.sslshopper.com/ssl-checker.html)

[decoder.link/sslchecker](https://decoder.link/sslchecker/)

[how-to-install-ssl-certificates](https://www.namecheap.com/support/knowledgebase/article.aspx/795/69/how-to-install-ssl-certificates/)

## Verify the Private Key and Certificate Match

```
openssl rsa -noout -modulus -in private.key | openssl md5
openssl x509 -noout -modulus -in your_SSL.crt | openssl md5
```

## Verify the Intermediate Bundle

```
openssl crl2pkcs7 -nocrl -certfile novablog_me.ca-bundle | openssl pkcs7 -print_certs -text -noout
```