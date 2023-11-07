# Class 09 

## Lecture slides

The slides for this lecture can be found here: [IoT slides](https://discord.com/channels/1064132619735928932/1163216523062689862/1168288756017668187).

# IoT Security Vulnerability Analysis

In the realm of the Internet of Things (IoT), it is crucial to recognize and tackle security weaknesses to guarantee the reliability and protection of interconnected devices and systems. This report aims to assess security weaknesses within an IoT setting and recommend actions to rectify these weaknesses.

## Scenario Description

*Situation*: We possess an Internet of Things (IoT) framework comprising various intelligent domestic devices like smart thermostats, security cameras, and smart locks. These devices link to a central unit that interacts with a mobile application, enabling remote oversight and management.

## Security Vulnerabilities

### 1. Insufficient Encryption

**Issue**: The communication link between the central hub and IoT devices might lack robust encryption, making it vulnerable to eavesdropping and data interception.

**Countermeasures**: Employ strong encryption protocols (such as TLS) to safeguard data transmitted between devices and the central hub.

### 2. Default Login Credentials

**Issue**: IoT devices often retain default usernames and passwords, which are seldom changed by users, presenting an easy target for potential attackers.

**Countermeasures**: Enforce stringent password policies, require users to establish unique and robust passwords during setup, and encourage regular password updates.

### 3. Firmware Weaknesses

**Issue**: Outdated or susceptible firmware in IoT devices can be exploited by attackers to gain unauthorized system access.

**Countermeasures**: Ensure routine firmware updates and patches. Integrate automatic update mechanisms to maintain device security.

### 4. Inadequate Verification

**Issue**: Weak or absent authentication methods may grant unauthorized entry to the central hub or mobile app.

**Countermeasures**: Implement multi-factor authentication (MFA) and robust authentication procedures to prevent unauthorized access.

### 5. Insufficient Device Segregation

**Issue**: Compromise of one IoT device might lead to unauthorized access to the entire network, jeopardizing other devices.

**Countermeasures**: Establish network segmentation to isolate IoT devices from critical systems. Use firewalls and access controls to restrict device communication.

### 6. Privacy Risks

**Issue**: Insufficient data privacy practices may result in the exposure of sensitive information gathered by IoT devices.

**Countermeasures**: Clearly articulate data usage and privacy policies to users. Apply data anonymization and data protection techniques.

## Conclusion

Security in IoT scenarios is critical for safeguarding both user data and the integrity of connected devices. Addressing vulnerabilities through a combination of technical measures, user education, and regular updates is essential for a secure IoT environment.

---

# Chain of Trust in SSL/TLS

In the world of secure communication, a chain of trust plays a critical role in ensuring the authenticity and integrity of digital certificates. This document will explain various aspects of the chain of trust in SSL/TLS, along with examples.

---

## What is a Cipher Suite?

A *cipher suite* is a combination of cryptographic algorithms used in SSL/TLS to secure communication. It includes algorithms for key exchange, encryption, and message authentication.

Example: The cipher suite "TLS_ECDHE_RSA_WITH_AES_256_GCM_SHA384" uses the Elliptic Curve Diffie-Hellman key exchange, RSA for digital signatures, AES for encryption, and SHA-384 for message authentication.

---

## What is a Chain of Trust?

A *chain of trust* is a hierarchical structure of digital certificates used to establish the authenticity of a website or service. It involves multiple certificate authorities to verify the identity of the entities involved.

Example: When you visit a secure website (e.g., https://www.example.com), your browser checks the server's SSL/TLS certificate. If it trusts the certificate, a chain of trust is formed.

---

## What is the Root Certificate Authority (CA)?

The *root certificate authority (CA)* is the topmost entity in the certificate hierarchy. It issues certificates to intermediate CAs and end entities, and its certificate is self-signed.

Example: The "DigiCert Global Root CA" is a widely recognized root CA in the SSL/TLS ecosystem.

---

## What is an Intermediate Certificate Authority (ICA)?

An *intermediate certificate authority (ICA)* is a CA that is not the root CA but is authorized by the root CA to issue certificates on its behalf.

Example: "DigiCert SHA-2 Secure Server CA" is an intermediate CA that issues certificates for websites on behalf of the DigiCert root CA.

---

## What is an End-User Certificate?

An *end-user certificate* is a certificate issued to an individual or entity (e.g., a website) to prove its identity in secure communication.

Example: The SSL certificate for "www.example.com" is an end-user certificate.

---

## What Topological Structure of Certificates is Created by a CA?

A *Certificate Authority (CA)* creates a hierarchical structure where the root CA is at the top, followed by intermediate CAs and end-user certificates. This structure forms the chain of trust.

---

## What is the Depth of a Certificate?

The *depth of a certificate* is the position of the certificate in the chain of trust, with the root CA at depth 0.

Example: An end-user certificate issued by an intermediate CA has a depth of 1.

---

## The CA Chain of Trust is a Representative for the Trust Chain Type "Root of Trust"

Yes, the CA chain of trust is a representative of the trust chain type called "root of trust," which relies on the ultimate trustworthiness of the root CA.

---

## What is the Name of Another Prominent Representative of a Chain of Trust?

Another prominent representative of a chain of trust is the *Web of Trust* used in PGP (Pretty Good Privacy). It's a decentralized model where trust is established through peers' verification.

---

## How Do Root of Trust and Web of Trust Differ?

* Root of Trust: Centralized, relies on a single, trusted root CA.
* Web of Trust: Decentralized, relies on peers' verification and endorsements.

---

## Which One is More Secure?

The security of Root of Trust and Web of Trust depends on the context. Root of Trust is more common in the context of SSL/TLS, offering strong security. Web of Trust is more flexible but can be vulnerable to untrustworthy peers.

---

# Diffie-Hellman Key Exchange and SSL/TLS

*Diffie-Hellman key exchange* is a cryptographic method used to securely exchange encryption keys over an insecure channel. It is commonly used in the context of *SSL/TLS* (Secure Sockets Layer/Transport Layer Security) to establish a secure and encrypted connection between a client (e.g., a web browser) and a server (e.g., a website).

SSL/TLS protocols utilize Diffie-Hellman key exchange to negotiate a shared secret key that will be used for encryption and decryption during the secure communication session. This shared key ensures that the data exchanged between the client and server remains confidential and protected from eavesdropping.

---

# RSA Key Exchange and SSL/TLS

*RSA key exchange* is a widely used asymmetric encryption method. It plays a crucial role in the context of *SSL/TLS* (Secure Sockets Layer/Transport Layer Security), enabling secure and encrypted communication between a client (e.g., a web browser) and a server (e.g., a website).

SSL/TLS protocols utilize RSA key exchange to securely exchange encryption keys. RSA is used for key pair generation, where the public key encrypts data, and the private key decrypts it. This key exchange method ensures the confidentiality and integrity of data during the communication session.

---

# Symmetric Certificate Validation

In the previous scenario, asymmetric validation was used, where only Bob validated the certificate of Alice. In symmetric validation, there are different considerations and security measures in place. This document will address the questions related to symmetric certificate validation.

---

## What Forces Bob to Validate Alice's Certificate?

*Force for Validation*: In symmetric certificate validation, Bob must validate Alice's certificate to ensure that he is connecting to the legitimate Alice. Without validation, there is a risk of connecting to an imposter or unauthorized entity, potentially compromising the security of the communication.

---

## Is It Possible to Also Force Alice to Validate Bob's Identity?

*Mutual Validation*: Yes, it is possible to force Alice to validate Bob's identity in a symmetric validation setup. This is achieved by having Alice validate Bob's certificate in a manner similar to how Bob validates Alice's certificate. Mutual validation ensures that both parties are certain about each other's identities and the security of the communication.

---

## Which Additional Certificates Are Necessary?

In a symmetric certificate validation setup, the following certificates are necessary:

1. *Alice's Certificate*: Alice must possess a certificate signed by the Certificate Authority (CA).
2. *Bob's Certificate*: Bob also needs a certificate signed by the same or a trusted CA.
3. *Root Certificate Authority (CA) Certificate*: Both Alice and Bob must have the CA's root certificate to validate each other's certificates.

The root CA certificate is necessary for verifying the authenticity and trustworthiness of Alice and Bob's certificates. It acts as a common trust anchor for both parties, ensuring secure communication.

---



# Exploring OpenWRT

OpenWRT is an open-source firmware/operating system used in (WiFi) routers. It provides a largely POSIX-compliant Linux kernel and standard libraries, using the musl libc. This allows for bringing most Linux software to OpenWRT-based devices, with the limiting factors being device resources such as RAM, flash memory, and system performance.

For more information, you can visit the [OpenWRT website](https://openwrt.org/).

## Tasks in OpenWRT

## Accessing the WEB Interface of OpenWRT

1. Open a web browser.
2. Enter the IP address of your router, which is 192.168.12.254, into the browser's address bar.
3. You will be directed to the OpenWRT web interface, where you can configure and manage your router.

## Discovering the Symbolic Host Name of the LAN Interface Address

The symbolic host name of the LAN interface address can typically be found in the OpenWRT web interface under the "Network" or "Interfaces" section. It is often labeled as the router's hostname or LAN domain name.

## SSH into the Router Using IP Address or Symbolic Host Name

To SSH into the router, open a terminal on your computer and use the following command:

```shell
ssh root@192.168.12.254
```

Replace 192.168.12.254 with the IP address of your router. You can also use the symbolic host name if it has been configured.

## SFTP into the Router and Upload/Download Files

You can use an SFTP client, such as sftp or graphical clients like FileZilla, to securely transfer files to and from the router. Here's a basic sftp example:

To upload a file:
```shell
sftp root@192.168.12.254
put local_file remote_directory/
```

To download a file:

```shell
sftp root@192.168.12.254
get remote_file local_directory/
```

## Installing New Packages on the Router

### Using the WEB Interface:

1. Log in to the OpenWRT web interface.
2. Navigate to the "System" tab.
3. Select "Software" from the sub-menu.
4. Use the "Available Packages" section to search for and install new packages.

### Using the opkg Command Line Utility:

To install packages via the command line, SSH into the router and use the opkg command. For example, to install a package:

```shell
opkg update
opkg install nano
```

## Remote Package Repositories

The remote package repositories in OpenWRT are configured in the /etc/opkg/distfeeds.conf file. This file contains the URLs of the repositories from which opkg fetches packages. You can modify this file to add, remove, or change package sources.

# Add Package Repository to OpenWRT

For a comprehensive and detailed exposition of this project, please refer to the dedicated section located within [linked here](../../../Jesper%20Hartsuiker/Lab/30-10-2023.md#group-task-add-package-repository-to-openwrt).