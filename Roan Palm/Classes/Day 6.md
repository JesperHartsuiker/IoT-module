## Secure the Network Connections using SSL/TLS

### Identify Security Risks

#### Tasks (group): Analyse your IoT scenario for vulnerabilities
- **Security vulnerabilities encountered**:
  - Unencrypted data transfer.
  - Accessibility limited to the local network.
  - Lack of security measures on the MQTT broker.
  - Non-disclosure of IP addresses.
- **Measures to close vulnerabilities**:
  - Encrypt data using hashing before transmission and decryption upon reception.
  - Utilize a VPN for external network connections.
  - Strengthen MQTT broker security with port changes, robust login credentials, and access control.
  - Anonymize IP addresses by hashing and configuring access points.

### Encryption Models: Symmetric and Asymmetric

- **Symmetric Encryption**: Utilizes a single key for encryption and decryption, whereas
- **Asymmetric Encryption**: Relies on a key pair (public and private).

### SSL/TLS, Certificate Authorities, and Chain of Trust

#### Key Concepts
- **Cipher Suite**: Defines cryptographic algorithms for secure network communication.
- **Chain of Trust**: A series of certificates validating entities in a network.
- **Root Certificate Authority (CA)**: Highest entity issuing digital certificates.
- **Intermediate Certificate Authority (ICA)**: Subordinate to the root CA, capable of issuing certificates on its behalf.
- **End-User Certificate**: Authenticates individual identities within the system.
- **CA Hierarchy**: Establishes a hierarchical structure resembling a tree.
- **Certificate Depth**: Position of a certificate in the chain of trust, counted from the root.

#### Trust Chain Types
- **Root of Trust and Web of Trust**: Different trust models.
- **Differences**:
  - Root of Trust: Centralized hierarchy.
  - Web of Trust: Decentralized and peer-based.
- **Security Comparison**: Neither inherently more secure; security depends on the implementation and context.

### Diffie-Hellman and RSA Key Exchange

- **Diffie-Hellman Key Exchange**: Facilitates secure key exchange within SSL/TLS.
- **RSA Key Exchange**: Another algorithm used in SSL/TLS for secure data transmission.

### Securing Network Communication with SSL/TLS: Scenario Overview

- **TCP Connection Scenario**:
  - Bob (client) connects with Alice (server), exchanging certificates.
  - Mutual validation of certificates using a trusted CA's public key.
  - Encryption established using public and private keys for secure communication.

### Symmetric Validation

- **Asymmetric Validation**: Bob validates Alice's certificate.
- **Symmetric Validation**: Alice needs a CA-signed certificate sent to Bob for validation.

#### Group Task: Recap and Clarification
- **Bob's Validation of Alice's Certificate**: Ensures secure communication.
- **Alice's Validation of Bob's Identity**: Achievable by receiving Bob's CA-signed certificate.
- **Necessary Certificates**: Include Alice's, Bob's, and a trusted CA-signed certificate for authentication.
